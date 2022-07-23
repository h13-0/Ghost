#ifndef SIMULATORUI_HPP
#define SIMULATORUI_HPP

#include "ui_Simulator.h"

#include "GhostPlatformConfigs.h"

#include <mutex>
#include <string>
#include <vector>
#include <regex>

// Qt headers.
#include <QMainWindow>
#include <QPainter>
#include <QStandardItemModel>

class SimulatorUI : public QMainWindow
{
    Q_OBJECT

public:
    SimulatorUI(QWidget *parent = Q_NULLPTR);
    SimulatorUI(const SimulatorUI&) = delete;
    ~SimulatorUI();

    /// <summary>
    /// Judge whether the current simulator has been initialized.
    /// </summary>
    /// <param name=""></param>
    /// <returns>Return ture if the simulator initialized.</returns>
    bool inited(void)
    {
        std::unique_lock<std::mutex> lck(loadFinishedFlagMutex);
        return loadFinishedFlag;
    }


    /// <summary>
    /// Typedef of GhostQtLevel_t.
    ///     Should be same as GhostLogLevel_t
    /// </summary>
    typedef enum
    {
        Debug = 0,
        Info = 1,
        Warning = 2,
        Error = 3,
        Fatal = 4
    } GhostQtLogLevel_t;


    /// <summary>
    /// Output log to Qt simulator ui.
    /// </summary>
    /// <param name="Level">Log level in GhostLogLevel_t.</param>
    /// <param name="Time">Microseconds since startup.</param>
    /// <param name="FileName">File name with error.</param>
    /// <param name="LineNumber">Line number with errors.</param>
    /// <param name="Contents">Log contents.</param>
    void log(GhostQtLogLevel_t Level, double Time, const char* FileName, int LineNumber, const char* Contents);


signals:
    /// <summary>
    /// Draw pixels in Screen View.
    /// </summary>
    /// <param name="X">X coordinate from 0.</param>
    /// <param name="Y">Y coordinate from 0.</param>
    /// <param name="Width">Width.</param>
    /// <param name="Height">Height.</param>
    /// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
    void drawScreen(int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels);


    /// <summary>
    /// Clear log area of QtSimulator.
    /// </summary>
    void logClear(void);

    /// <summary>
    /// Get the resolution of screen in the simulator.
    /// </summary>
    int getScreenWidth(void);
    int getScreenHeight(void);

    /// <summary>
    /// Set value of performance monitor area progress bar.
    /// </summary>
    /// <param name="value">Value of progress bar, range [0, 100].</param>
    void setCPU_UsageProgressBarValue(int value);
    void setMemoryUsageProgressBarValue(int value);

private:
    // Private UI variables.
    Ui::MainWindow ui;
    QGraphicsScene* screenScene;
    QStandardItemModel* model;

    /// <summary>
    /// Typedef of Ghost Qt log.
    /// </summary>
    /// <param name="Level">Log level in GhostQtLogLevel_t.</param>
    /// <param name="FileName">File name with error.</param>
    /// <param name="LineNumber">Line number with errors.</param>
    /// <param name="Contents">Log contents.</param>
    typedef struct
    {
        GhostQtLogLevel_t level;
        double time;
        std::string fileName;
        int lineNumber;
        std::string contents;
    } GhostQtLog_t;


    /// <summary>
    /// Typedef of GhostQtLogDisplayOptions.
    /// </summary>
    /// <param name="showInfo"></param>
    /// <param name="showDebug"></param>
    /// <param name="showWarning"></param>
    /// <param name="showError"></param>
    /// <param name="showFatal"></param>
    /// <param name="regex"></param>
    typedef struct
    {
        bool showInfo;
        bool showDebug;
        bool showWarning;
        bool showError;
        bool showFatal;
        std::regex regex;
    } GhostQtLogDisplayOptions_t;


    /// <summary>
    /// Generate log contents according to log and options.
    /// </summary>
    /// <param name="log"></param>
    /// <returns>Returns true and generates a QString if GhostQtLogDisplayOptions are matched.</returns>
    bool logStringGenerate(const GhostQtLog_t& log, const GhostQtLogDisplayOptions_t& Options, QString& Content);
    

    /// <summary>
    /// Add a new log after the current log area.
    /// </summary>
    /// <param name="log">New log.</param>
    void logAppend(const GhostQtLog_t& log, const GhostQtLogDisplayOptions_t& Options);


    /// <summary>
    /// Refresh log output (this function should be called after the log is updated or the filter condition is changed).
    /// </summary>
    void refreshLogOutput(void); // Change log display option.?

    // Qt log variables.
    std::mutex logMutex;
    std::vector<GhostQtLog_t> logBuffer;
    GhostQtLogDisplayOptions_t logOptions;


    // Screen image buffer.
    unsigned char* screenRawBuffer = nullptr;

    // Load finished flage variables.
    std::mutex loadFinishedFlagMutex;
    bool loadFinishedFlag = false;


private slots:
    /// <summary>
    /// Draw Screen slot function.
    /// </summary>
    /// <param name="X">X coordinate from 0.</param>
    /// <param name="Y">Y coordinate from 0.</param>
    /// <param name="Width">Width.</param>
    /// <param name="Height">Height.</param>
    /// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
    void drawScreenMethod(int X, int Y, int Width, int Height, const unsigned char* ARGB32_Pixels);


    /// <summary>
    /// Append log in the log area of QtSimulator.
    /// </summary>
    /// <param name="Level">Log level in GhostLogLevel_t.</param>
    /// <param name="FileName">File name with error.</param>
    /// <param name="LineNumber">Line number with errors.</param>
    /// <param name="Contents">Log contents.</param>
    //void logAppendImpl(GhostQtLogLevel_t Level, std::string FileName, int LineNumber, std::string Contents);
};

#endif // SIMULATORUI_H
