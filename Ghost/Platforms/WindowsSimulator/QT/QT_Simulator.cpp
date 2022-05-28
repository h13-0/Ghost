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

GhostError_t GhostQT_SimulatorGetResolution(GhostQT_Simulator_t* QT_Simulator, int* X_Resolution, int* Y_Resolution)
{
	return GhostOK;
}

GhostError_t GhostQT_SimulatorDraw(GhostQT_Simulator_t* QT_Simulator)
{
	return GhostError_t();
}

/// <summary>
/// Draw image in the virtual screen of the simulator.
/// </summary>
/// <param name="QT_Simulator">Simulator pointor.</param>
/// <param name="X">X coordinate from 0.</param>
/// <param name="Y">Y coordinate from 0.</param>
/// <param name="Width">Width.</param>
/// <param name="Height">Height.</param>
/// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
/// <returns>GhostError_t</returns>
GhostError_t GhostQT_SimulatorDrawScreen(GhostQT_Simulator_t* QT_Simulator, int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels)
{
	if (!QT_Simulator->QApplicationPtr || !QT_Simulator->SimulatorUI_Ptr)
	{
		return GhostError_QT_SimulatorUninitialized;
	}

	((SimulatorUI*)(QT_Simulator->SimulatorUI_Ptr))->DrawScreen(X, Y, Width, Height, ARGB32_Pixels);
	return GhostOK;
}

GhostError_t GhostQT_SimulatorSetTouchEventsCallback(GhostQT_Simulator_t* QT_Simulator, void(*CallbackPtr)(int X, int Y))
{
	return GhostError_t();
}

GhostError_t GhostQT_SimulatorInited(GhostQT_Simulator_t* QT_Simulator)
{
	if (QT_Simulator)
	{
		if (((SimulatorUI*)(QT_Simulator->SimulatorUI_Ptr))->inited())
		{
			return GhostOK;
		}
	}

	return GhostError_QT_SimulatorUninitialized;
}

GhostError_t GhostQT_SimulatorDraw(void)
{
	return GhostOK;
}

GhostError_t GhostQT_SimulatorSetTouchEventsCallback(void)
{
	return GhostOK;
}
