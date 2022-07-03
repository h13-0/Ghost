// File: QtSimulator.h
// Author: h13
// Note: This file is responsible for passing the C + + interface to the C language interface.

#pragma once

#include "GhostPlatformErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GhostError_QtSimulatorInitFaild        DeclareGhostError(GhostPlatformLayerError, PlatformModuleQtError, 1)
#define GhostError_QtSimulatorUninitialized    DeclareGhostError(GhostPlatformLayerError, PlatformModuleQtError, 2)
#define GhostError_QtSimulatorUnexpectedExit   DeclareGhostError(GhostPlatformLayerError, PlatformModuleQtError, 3)

	typedef struct
	{
		void* QApplicationPtr;
		void* SimulatorUI_Ptr;
	} GhostQtSimulator_t;
	
	
	/// <summary>
	/// Init QT Simulator.
	/// </summary>
	/// <param name="QtSimulator">Simulator pointor.</param>
	/// <param name="argc"></param>
	/// <param name="argv"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostQtSimulatorInit(GhostQtSimulator_t* QtSimulator, int argc, char** argv);

	
	/// <summary>
	/// Run QT Simulator.
	/// </summary>
	/// <param name="QtSimulator">Simulator pointor.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostQtSimulatorRun(GhostQtSimulator_t* QtSimulator);

	
	/// <summary>
	/// Draw image in the virtual screen of the simulator.
	/// </summary>
	/// <param name="QtSimulator">Simulator pointor.</param>
	/// <param name="X">X coordinate from 0.</param>
	/// <param name="Y">Y coordinate from 0.</param>
	/// <param name="Width">Width.</param>
	/// <param name="Height">Height.</param>
	/// <param name="ARGB32_Pixels">ARGB32 Pixels in uint8_t.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostQtSimulatorDrawScreen(GhostQtSimulator_t* QtSimulator, int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels);


	/// <summary>
	/// Get screen resolution.
	/// </summary>
	/// <param name="QtSimulator">Pointor to simulator.</param>
	/// <param name="Width">Width.</param>
	/// <param name="Hegith">Hegith.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostQtSimulatorGetScreenResolution(GhostQtSimulator_t* QtSimulator, int* Width, int* Height);
	GhostError_t GhostQtSimulatorGetScreenWidth(GhostQtSimulator_t* QtSimulator, int* Width);
	GhostError_t GhostQtSimulatorGetScreenHeight(GhostQtSimulator_t* QtSimulator, int* Height);

	
	/// <summary>
	/// Get screen fillet radius.
	/// </summary>
	/// <param name="QtSimulator">Pointor to simulator.</param>
	/// <param name="Radius">Radius.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostQtSimulatorGetRadius(GhostQtSimulator_t* QtSimulator, int* Radius);

	
	/// <summary>
	/// Typedef of GhostQtLevel_t.
	///     Should be same as GhostLogLevel_t
	/// </summary>
	typedef enum
	{
		QtSimDebug = 0,
		QtSimInfo = 1,
		QtSimWarning = 2,
		QtSimError = 3,
		QtSimFatal = 4
	} GhostQtSimLogLevel_t;


	/// <summary>
	/// Output log to Qt simulator ui.
	/// </summary>
	/// <param name="QtSimulator">Pointor to simulator.</param>
	/// <param name="Level">Log level in GhostLogLevel_t.</param>
	/// <param name="Time">Microseconds since startup.</param>
	/// <param name="FileName">File name with error.</param>
	/// <param name="LineNumber">Line number with errors.</param>
	/// <param name="Contents">Log contents.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostQtSimulatorLog(GhostQtSimulator_t* QtSimulator, GhostQtSimLogLevel_t Level, double Time, const char* FileName, int LineNumber, const char* Contents);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="QtSimulator">Simulator pointor.</param>
	/// <param name="CallbackPtr"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostQtSimulatorSetTouchEventsCallback(GhostQtSimulator_t* QtSimulator, void (*CallbackPtr)(int X, int Y));

	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="QtSimulator">Simulator pointor.</param>
	/// <returns>GhostOK will be returned if initialization is completed.</returns>
	GhostError_t GhostQtSimulatorInited(GhostQtSimulator_t* QtSimulator);

	
#ifdef __cplusplus
}
#endif
