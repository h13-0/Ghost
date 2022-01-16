#ifndef SIMULATORUI_HPP
#define SIMULATORUI_HPP

#include <QWidget>

namespace SimulatorUI {
class SimulatorUI;
}

class SimulatorUI : public QWidget
{
    Q_OBJECT

public:
    explicit SimulatorUI(QWidget *parent = nullptr);
    ~SimulatorUI();

private:
    SimulatorUI::SimulatorUI *ui;
};

#endif // SIMULATORUI_H
