#include "QT_Simulator.h"

#include "SimulatorUI.hpp"


/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhQT_Error_t GhQT_SimulatorInit(GhQT_Simulator_t* QT_Simulator)
{
	QT_Simulator = new SimulatorUI();
}

GhQT_Error_t GhQT_SimulatorGetResolution(GhQT_Simulator_t* QT_Simulator, int* X_Resolution, int* Y_Resolution)
{

}

GhQT_Error_t GhQT_SimulatorDraw(void)
{

}

GhQT_Error_t GhQT_SimulatorSetTouchEventsCallback(void)
{

}

GhQT_Error_t GhQT_SimulatorDestory(GhQT_Simulator_t* QT_Simulator)
{
	delete QT_Simulator;
}
