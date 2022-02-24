#ifndef SIMULATORUI_HPP
#define SIMULATORUI_HPP

#include <QMainWindow>
#include "ui_Simulator.h"

class SimulatorUI : public QMainWindow
{
    Q_OBJECT

public:
    SimulatorUI(QWidget *parent = Q_NULLPTR);
    SimulatorUI(const SimulatorUI&) = delete;
    ~SimulatorUI();

private:
    Ui::MainWindow ui;
};

#endif // SIMULATORUI_H
