#include "QtSimulator.h"
#include "SimulatorUI.hpp"
//#include "GhostLog.h"

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostQtSimulatorInit(GhostQtSimulator_t* QtSimulator, int argc, char** argv)
{
	try {
		QtSimulator -> QApplicationPtr = new QApplication(argc, argv);
		QtSimulator -> SimulatorUI_Ptr = new SimulatorUI();
	}
	catch (...)
	{
		QtSimulator->QApplicationPtr = nullptr;
		QtSimulator->SimulatorUI_Ptr = nullptr;
		return GhostError_QtSimulatorInitFaild;
	}
	return GhostOK;
}

GhostError_t GhostQtSimulatorRun(GhostQtSimulator_t* QtSimulator)
{
	((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->show();
	int ret = ((QApplication*)(QtSimulator->QApplicationPtr))->exec();
	if (!ret)
	{
		return GhostOK;
	}
	else {
		return GhostError_QtSimulatorUnexpectedExit;
	}
	
}

GhostError_t GhostQtSimulatorGetResolution(GhostQtSimulator_t* QtSimulator, int* X_Resolution, int* Y_Resolution)
{
	return GhostOK;
}

GhostError_t GhostQtSimulatorDraw(GhostQtSimulator_t* QtSimulator)
{
	return GhostError_t();
}

/// <summary>
/// Draw image in the virtual screen of the simulator.
/// </summary>
/// <param name="QtSimulator">Simulator pointor.</param>
/// <param name="X">X coordinate from 0.</param>
/// <param name="Y">Y coordinate from 0.</param>
/// <param name="Width">Width.</param>
/// <param name="Height">Height.</param>
/// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
/// <returns>GhostError_t</returns>
GhostError_t GhostQtSimulatorDrawScreen(GhostQtSimulator_t* QtSimulator, int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels)
{
	if (!QtSimulator->QApplicationPtr || !QtSimulator->SimulatorUI_Ptr)
	{
		return GhostError_QtSimulatorUninitialized;
	}

	((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->DrawScreen(X, Y, Width, Height, ARGB32_Pixels);
	return GhostOK;
}

GhostError_t GhostQtSimulatorSetTouchEventsCallback(GhostQtSimulator_t* QtSimulator, void(*CallbackPtr)(int X, int Y))
{
	return GhostError_t();
}

GhostError_t GhostQtSimulatorInited(GhostQtSimulator_t* QtSimulator)
{
	if (QtSimulator)
	{
		if (((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->inited())
		{
			return GhostOK;
		}
	}

	return GhostError_QtSimulatorUninitialized;
}

GhostError_t GhostQtSimulatorDraw(void)
{
	return GhostOK;
}

GhostError_t GhostQtSimulatorSetTouchEventsCallback(void)
{
	return GhostOK;
}
