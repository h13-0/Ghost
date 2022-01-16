#include "SimulatorUI.hpp"
#include "ui_SimulatorUI.h"

SimulatorUI::SimulatorUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulatorUI)
{
    ui->setupUi(this);
}

SimulatorUI::~SimulatorUI()
{
    delete ui;
}
