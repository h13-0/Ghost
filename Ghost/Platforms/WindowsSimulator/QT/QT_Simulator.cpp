#include "QT_Simulator.h"
#include "SimulatorUI.hpp"
//#include "GhostLog.h"

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostQT_SimulatorInit(GhostQT_Simulator_t* QT_Simulator, int argc, char** argv)
{
	try {
		QT_Simulator -> QApplicationPtr = new QApplication(argc, argv);
		QT_Simulator -> SimulatorUI_Ptr = new SimulatorUI();
	}
	catch (...)
	{
		QT_Simulator->QApplicationPtr = nullptr;
		QT_Simulator->SimulatorUI_Ptr = nullptr;
		return GhostError_QT_SimulatorInitFaild;
	}
	return GhostOK;
}

GhostError_t GhostQT_SimulatorRun(GhostQT_Simulator_t* QT_Simulator)
{
	((SimulatorUI*)(QT_Simulator->SimulatorUI_Ptr))->show();
	int ret = ((QApplication*)(QT_Simulator->QApplicationPtr))->exec();
	if (!ret)
	{
		return GhostOK;
	}
	else {
		return GhostError_QT_SimulatorUnexpectedExit;
	}
	
}

GhostError_t GhostQT_SimulatorShow(void)
{
	return GhostOK;
}

GhostError_t GhostQT_SimulatorGetResolution(GhostQT_Simulator_t* QT_Simulator, int* X_Resolution, int* Y_Resolution)
{
	return GhostOK;
}

GhostError_t GhostQT_SimulatorDraw(GhostQT_Simulator_t* QT_Simulator)
{
	return GhostError_t();
}

GhostError_t GhostQT_SimulatorSetTouchEventsCallback(GhostQT_Simulator_t* QT_Simulator, void(*CallbackPtr)(int X, int Y))
{
	return GhostError_t();
}

GhostError_t GhostQT_SimulatorDraw(void)
{
	return GhostOK;
}

GhostError_t GhostQT_SimulatorSetTouchEventsCallback(void)
{
	return GhostOK;
}
