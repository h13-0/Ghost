#ifndef SIMULATORUI_HPP
#define SIMULATORUI_HPP

#include "ui_Simulator.h"

#include "GhostPlatformConfigs.h"

#include <QMainWindow>
#include <QPainter>

class SimulatorUI : public QMainWindow
{
    Q_OBJECT

public:
    SimulatorUI(QWidget *parent = Q_NULLPTR);
    SimulatorUI(const SimulatorUI&) = delete;
    ~SimulatorUI();

signals:
    /// <summary>
    /// Draw pixels in Screen View.
    /// </summary>
    /// <param name="X">X coordinate from 0.</param>
    /// <param name="Y">Y coordinate from 0.</param>
    /// <param name="Width">Width.</param>
    /// <param name="Height">Height.</param>
    /// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
    void DrawScreen(int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels);

private:
    Ui::MainWindow ui;

    // Screen image buffer.
    unsigned char screenRawBuffer[MacroDisplayHorizontalResolution * MacroDisplayVerticalResolution * 4] = { 0 };

private slots:
    /// <summary>
    /// Draw Screen slot function.
    /// </summary>
    /// <param name="X">X coordinate from 0.</param>
    /// <param name="Y">Y coordinate from 0.</param>
    /// <param name="Width">Width.</param>
    /// <param name="Height">Height.</param>
    /// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
    void drawScreenMethod(int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels);

};

#endif // SIMULATORUI_H
