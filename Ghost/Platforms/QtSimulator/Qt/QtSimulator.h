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
	/// <returns></returns>
	GhostError_t GhostQtSimulatorInit(GhostQtSimulator_t* QtSimulator, int argc, char** argv);

	/// <summary>
	/// Run QT Simulator.
	/// </summary>
	/// <param name="QtSimulator">Simulator pointor.</param>
	/// <returns>GhostError_t</returns>
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
	/// <returns>GhostError_t</returns>
	GhostError_t GhostQtSimulatorDrawScreen(GhostQtSimulator_t* QtSimulator, int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels);

	GhostError_t GhostQtSimulatorGetScreenResolution(GhostQtSimulator_t* QtSimulator, int* X_Resolution, int* Y_Resolution);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="QtSimulator">Simulator pointor.</param>
	/// <param name="CallbackPtr"></param>
	/// <returns></returns>
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
