// File: QT_Simulator.h
// Author: h13
// Note: This file is responsible for passing the C + + interface to the C language interface.

#pragma once

#include "GhostPlatformErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GhostError_QT_SimulatorInitFaild        DeclareGhostError(GhostPlatformLayerError, PlatformModuleQT_Error, 1)
#define GhostError_QT_SimulatorUnexpectedExit   DeclareGhostError(GhostPlatformLayerError, PlatformModuleQT_Error, 2)

	typedef struct
	{
		void* QApplicationPtr;
		void *SimulatorUI_Ptr;
	} GhostQT_Simulator_t;

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhostError_t GhostQT_SimulatorInit(GhostQT_Simulator_t* QT_Simulator, int argc, char** argv);

	GhostError_t GhostQT_SimulatorRun(GhostQT_Simulator_t* QT_Simulator);

	GhostError_t GhostQT_SimulatorGetResolution(GhostQT_Simulator_t* QT_Simulator, int* X_Resolution, int* Y_Resolution);

	GhostError_t GhostQT_SimulatorDraw(GhostQT_Simulator_t* QT_Simulator);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="QT_Simulator"></param>
	/// <param name="CallbackPtr"></param>
	/// <returns></returns>
	GhostError_t GhostQT_SimulatorSetTouchEventsCallback(GhostQT_Simulator_t* QT_Simulator, void (*CallbackPtr)(int X, int Y));

#ifdef __cplusplus
}
#endif
