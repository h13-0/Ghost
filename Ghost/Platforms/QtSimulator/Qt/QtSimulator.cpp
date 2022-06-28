#include "QtSimulator.h"
#include "SimulatorUI.hpp"


/// <summary>
/// Init QT Simulator.
/// </summary>
/// <param name="QtSimulator">Simulator pointor.</param>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns>Function execution result.</returns>
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


/// <summary>
/// Run QT Simulator.
/// </summary>
/// <param name="QtSimulator">Simulator pointor.</param>
/// <returns>Function execution result.</returns>
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

	((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->drawScreen(X, Y, Width, Height, ARGB32_Pixels);
	return GhostOK;
}


/// <summary>
/// Get screen resolution.
/// </summary>
/// <param name="QtSimulator">Pointor to simulator.</param>
/// <param name="Width">Width.</param>
/// <param name="Hegith">Hegith.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostQtSimulatorGetScreenResolution(GhostQtSimulator_t* QtSimulator, int* Width, int* Height)
{
	if (!QtSimulator->QApplicationPtr || !QtSimulator->SimulatorUI_Ptr)
	{
		return GhostError_QtSimulatorUninitialized;
	}

	*Width = ((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->getScreenWidth();
	*Height = ((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->getScreenHeight();
	
	return GhostOK;
}


/// <summary>
/// Output log to Qt simulator ui.
/// </summary>
/// <param name="QtSimulator">Pointor to simulator.</param>
/// <param name="Level">Log level in GhostLogLevel_t.</param>
/// <param name="FileName">File name with error.</param>
/// <param name="LineNumber">Line number with errors.</param>
/// <param name="Contents">Log contents.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostQtSimulatorLog(GhostQtSimulator_t* QtSimulator, GhostQtSimLogLevel_t Level, double Time, const char* FileName, int LineNumber, const char* Contents)
{
	if (!QtSimulator->QApplicationPtr || !QtSimulator->SimulatorUI_Ptr)
	{
		return GhostError_QtSimulatorUninitialized;
	}

	switch (Level)
	{
	case GhostQtSimLogLevel_t::QtSimDebug:
		((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->log(SimulatorUI::GhostQtLogLevel_t::Debug, Time, FileName, LineNumber, Contents);
		break;

	case GhostQtSimLogLevel_t::QtSimInfo:
		((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->log(SimulatorUI::GhostQtLogLevel_t::Info, Time, FileName, LineNumber, Contents);
		break;

	case GhostQtSimLogLevel_t::QtSimWarning:
		((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->log(SimulatorUI::GhostQtLogLevel_t::Warning, Time, FileName, LineNumber, Contents);
		break;

	case GhostQtSimLogLevel_t::QtSimError:
		((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->log(SimulatorUI::GhostQtLogLevel_t::Error, Time, FileName, LineNumber, Contents);
		break;

	case GhostQtSimLogLevel_t::QtSimFatal:
		((SimulatorUI*)(QtSimulator->SimulatorUI_Ptr))->log(SimulatorUI::GhostQtLogLevel_t::Fatal, Time, FileName, LineNumber, Contents);
		break;
	}

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
