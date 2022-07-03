#include "SimulatorUI.hpp"
#include "ui_Simulator.h"
#include "GhostPlatformConfigs.h"
#include <string.h>
#include <new>
#include <QTimer>
#include <QTableView>
#include <QStandardItemModel>

SimulatorUI::SimulatorUI(QWidget *parent) :
    QMainWindow(parent)
{
    Q_INIT_RESOURCE(Resources);
    ui.setupUi(this);

    // Init screenScene.
#if(MacroDynamicScreenResolution)
    screenRawBuffer = new unsigned char[(MacroQtMaximumHorizontalResolution * MacroQtMaximumVerticalResolution * 4)]();
#else
    screenRawBuffer = new unsigned char[(MacroDisplayHorizontalResolution * MacroDisplayVerticalResolution * 4)]();
#endif

    // Init log.
    logOptions.showInfo = true;
    logOptions.showDebug = true;
    logOptions.showWarning = true;
    logOptions.showError = true;
    logOptions.showFatal = true;


    // AW7 424-56*654-206 368*448
    screenScene = new QGraphicsScene();
    ui.screenView->setScene(screenScene);

    // Create screen image buffer.

    // Init log table.
    model = new QStandardItemModel();
    model->setColumnCount(5);
    model->setHeaderData(0, Qt::Horizontal, "Log level");
    model->setHeaderData(1, Qt::Horizontal, "Time(us)");
    model->setHeaderData(2, Qt::Horizontal, "File");
    model->setHeaderData(3, Qt::Horizontal, "Line");
    model->setHeaderData(4, Qt::Horizontal, "Content");
    ui.logTable->setModel(model);
    ui.logTable->horizontalHeader()->setStretchLastSection(true);

    // Connect signals and slots.
    connect(this, &SimulatorUI::drawScreen, this, &SimulatorUI::drawScreenMethod, Qt::BlockingQueuedConnection);
    connect(this, &SimulatorUI::logClear, this, [this](void) { model->removeRows(0, model->rowCount()); });
    connect(this, &SimulatorUI::getScreenWidth, this, [this](void) -> int { return this->ui.screenView->width(); }, Qt::BlockingQueuedConnection);
    connect(this, &SimulatorUI::getScreenHeight, this, [this](void) -> int { return this->ui.screenView->height(); }, Qt::BlockingQueuedConnection);

    QTimer::singleShot(0, this, [this] { std::unique_lock<std::mutex> lck(loadFinishedFlagMutex); loadFinishedFlag = true; });
}

SimulatorUI::~SimulatorUI()
{
    delete screenScene;
    delete screenRawBuffer;
    delete model;
    Q_CLEANUP_RESOURCE(Resources);
}


/// <summary>
/// Output log to Qt simulator ui.
/// </summary>
/// <param name="Level">Log level in GhostLogLevel_t.</param>
/// <param name="Time">Microseconds since startup.</param>
/// <param name="FileName">File name with error.</param>
/// <param name="LineNumber">Line number with errors.</param>
/// <param name="Contents">Log contents.</param>
void SimulatorUI::log(GhostQtLogLevel_t Level, double Time, const char* FileName, int LineNumber, const char* Contents)
{
    using namespace std;
    GhostQtLog_t newLog;

    unique_lock<mutex> lock(logMutex);
    {
        newLog.level = Level;
        newLog.time = Time;
        newLog.fileName = FileName;
        newLog.lineNumber = LineNumber;
        newLog.contents = Contents;

        logBuffer.push_back(newLog);
        logAppend(newLog, logOptions);
    }
}


/// <summary>
/// Generate log contents according to log and options.
/// </summary>
/// <param name="log"></param>
/// <returns>Returns true and generates a QString if GhostQtLogDisplayOptions are matched.</returns>
bool SimulatorUI::logStringGenerate(const GhostQtLog_t& log, const GhostQtLogDisplayOptions_t& Options, QString& Content)
{
    if (true) //TODO: Match with Options.regex.
    {
        bool matched = false;
        // Print log level.
        switch (log.level) {
        case Debug:
            if (Options.showDebug)
            {
                Content = QString("<font color=\"#000000\">%1").arg(QString::fromStdString("[Debug]: " + log.fileName + std::to_string(log.lineNumber) + log.contents));
                matched = true;
            }
            break;

        case Info:
            if (Options.showInfo)
            {
                Content = QString("<font color=\"#000000\">%1").arg(QString::fromStdString("[Info]: " + log.fileName + std::to_string(log.lineNumber) + log.contents));
                matched = true;
            }
            break;

        case Warning:
            if (Options.showWarning)
            {
                Content = QString("<font color=\"#FF0000\">%1").arg(QString::fromStdString("[Warn]: " + log.fileName + std::to_string(log.lineNumber) + log.contents));
                matched = true;
            }
            break;

        case Error:
            if (Options.showError)
            {
                Content = QString("<font color=\"#ff3300\">%1").arg(QString::fromStdString("[Error]: " + log.fileName + std::to_string(log.lineNumber) + log.contents));
                matched = true;
            }
            break;

        case Fatal:
            if (Options.showFatal)
            {
                Content = QString("<font color=\"#990000\">%1").arg(QString::fromStdString("[Fatal]: " + log.fileName + std::to_string(log.lineNumber) + log.contents));
                matched = true;
            }
            break;

        default:
            break;
        }

        if (!matched)
        {
            Content = "";
        }

        return matched;
    }
    else
    {
        return false;
    }
}


/// <summary>
/// Add a new log after the current log area.
/// </summary>
/// <param name="log">New log.</param>
void SimulatorUI::logAppend(const GhostQtLog_t& log, const GhostQtLogDisplayOptions_t& Options)
{
    QString content;
    if (logStringGenerate(log, logOptions, content))
    {
        int count = model->rowCount();
        switch (log.level)
        {
        case Debug:
            if (Options.showDebug)
            {
                model->setItem(count, 0, new QStandardItem("Debug"));
            }
            break;

        case Info:
            if (Options.showInfo)
            {
                model->setItem(count, 0, new QStandardItem("Info"));
            }
            break;
            
        case Warning:
            if (Options.showWarning)
            {
                model->setItem(count, 0, new QStandardItem("Warning"));
            }
            break;

        case Error:
            if (Options.showError)
            {
                model->setItem(count, 0, new QStandardItem("Error"));
            }
            break;

        case Fatal:
            if (Options.showFatal)
            {
                model->setItem(count, 0, new QStandardItem("Fatal"));
            }
            break;
            
        default:
            break;
        }

        model->setItem(count, 1, new QStandardItem(QString::number(log.time)));
        model->setItem(count, 2, new QStandardItem(QString::fromStdString(log.fileName)));
        model->setItem(count, 3, new QStandardItem(QString::number(log.lineNumber)));
        model->setItem(count, 4, new QStandardItem(QString::fromStdString(log.contents)));
        ui.logTable->resizeColumnsToContents();
    }
}


/// <summary>
/// Draw Screen slot function.
/// </summary>
/// <param name="X">X coordinate from 0.</param>
/// <param name="Y">Y coordinate from 0.</param>
/// <param name="Width">Width.</param>
/// <param name="Height">Height.</param>
/// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
void SimulatorUI::drawScreenMethod(int X, int Y, int Width, int Height, const unsigned char* ARGB32_Pixels)
{
    if (Width > 0)
    {
        for (int y = 0; y < Height; y++)
        {
            if (X >= 0)
            {
                memcpy((screenRawBuffer + (y + Y) * ui.screenView->width() * 4 + 4 * X), (ARGB32_Pixels + Width * y * 4), 4 * (X + Width <= ui.screenView->width() ? Width : ui.screenView->width() - X));
            }
            else {
                memcpy((screenRawBuffer + (y + Y) * ui.screenView->width() * 4), (ARGB32_Pixels + Width * y * 4), 4 * (X + Width <= ui.screenView->width() ? Width : ui.screenView->width()));
            }
        }

        QImage image = QImage(screenRawBuffer, ui.screenView->width(), ui.screenView->height(), QImage::Format_ARGB32);
        screenScene->clear();
        screenScene->addPixmap(QPixmap::fromImage(image));
    }
}
