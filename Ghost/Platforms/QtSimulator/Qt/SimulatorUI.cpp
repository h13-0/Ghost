#include "SimulatorUI.hpp"
#include "ui_Simulator.h"
#include "GhostPlatformConfigs.h"
#include <string.h>
#include <qtimer>

SimulatorUI::SimulatorUI(QWidget *parent) :
    QMainWindow(parent)
{
    Q_INIT_RESOURCE(Resources);
    ui.setupUi(this);

    // Init screenScene.

    // AW7 424-56*654-206 368*448

    screenScene = new QGraphicsScene();
    ui.screenView->setScene(screenScene);

    // Create screen image buffer.

    // Connect signals and slots.
    connect(this, &SimulatorUI::DrawScreen, this, &SimulatorUI::drawScreenMethod, Qt::BlockingQueuedConnection);

    QTimer::singleShot(0, this, [this] { std::unique_lock<std::mutex> lck(loadFinishedFlagMutex); loadFinishedFlag = true; });
}

SimulatorUI::~SimulatorUI()
{
    delete screenScene;
    Q_CLEANUP_RESOURCE(Resources);
}

/// <summary>
/// Draw Screen slot function.
/// </summary>
/// <param name="X">X coordinate from 0.</param>
/// <param name="Y">Y coordinate from 0.</param>
/// <param name="Width">Width.</param>
/// <param name="Height">Height.</param>
/// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
void SimulatorUI::drawScreenMethod(int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels)
{
    if (Width > 0)
    {
        for (int y = 0; y < Height; y++)
        {
            if (X >= 0)
            {
                memcpy((screenRawBuffer + (y + Y) * MacroDisplayHorizontalResolution * 4 + 4 * X), (ARGB32_Pixels + Width * y * 4), 4 * (X + Width <= MacroDisplayHorizontalResolution ? Width : MacroDisplayHorizontalResolution - X));
            }
            else {
                memcpy((screenRawBuffer + (y + Y) * MacroDisplayHorizontalResolution * 4), (ARGB32_Pixels + Width * y * 4), 4 * (X + Width <= MacroDisplayHorizontalResolution ? Width : MacroDisplayHorizontalResolution));
            }
        }

        QImage image = QImage(screenRawBuffer, MacroDisplayHorizontalResolution, MacroDisplayVerticalResolution, QImage::Format_ARGB32);
        screenScene->clear();
        screenScene->addPixmap(QPixmap::fromImage(image));
    }
}