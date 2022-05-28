// File: QT_Simulator.h
// Author: h13
// Note: This file is responsible for passing the C + + interface to the C language interface.

#pragma once

#include "GhostPlatformErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GhostError_QT_SimulatorInitFaild        DeclareGhostError(GhostPlatformLayerError, PlatformModuleQT_Error, 1)
#define GhostError_QT_SimulatorUninitialized    DeclareGhostError(GhostPlatformLayerError, PlatformModuleQT_Error, 2)
#define GhostError_QT_SimulatorUnexpectedExit   DeclareGhostError(GhostPlatformLayerError, PlatformModuleQT_Error, 3)

	typedef struct
	{
		void* QApplicationPtr;
		void* SimulatorUI_Ptr;
	} GhostQT_Simulator_t;
	
	/// <summary>
	/// Init QT Simulator.
	/// </summary>
	/// <param name="QT_Simulator">Simulator pointor.</param>
	/// <param name="argc"></param>
	/// <param name="argv"></param>
	/// <returns></returns>
	GhostError_t GhostQT_SimulatorInit(GhostQT_Simulator_t* QT_Simulator, int argc, char** argv);

	/// <summary>
	/// Run QT Simulator.
	/// </summary>
	/// <param name="QT_Simulator">Simulator pointor.</param>
	/// <returns>GhostError_t</returns>
	GhostError_t GhostQT_SimulatorRun(GhostQT_Simulator_t* QT_Simulator);

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
	GhostError_t GhostQT_SimulatorDrawScreen(GhostQT_Simulator_t* QT_Simulator, int X, int Y, int Width, int Height, unsigned char* ARGB32_Pixels);

	GhostError_t GhostQT_SimulatorGetScreenResolution(GhostQT_Simulator_t* QT_Simulator, int* X_Resolution, int* Y_Resolution);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="QT_Simulator">Simulator pointor.</param>
	/// <param name="CallbackPtr"></param>
	/// <returns></returns>
	GhostError_t GhostQT_SimulatorSetTouchEventsCallback(GhostQT_Simulator_t* QT_Simulator, void (*CallbackPtr)(int X, int Y));

	/// <summary>
	/// 
	/// </summary>
	/// <param name="QT_Simulator">Simulator pointor.</param>
	/// <returns>GhostOK will be returned if initialization is completed.</returns>
	GhostError_t GhostQT_SimulatorInited(GhostQT_Simulator_t* QT_Simulator);

#ifdef __cplusplus
}
#endif
