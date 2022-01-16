// File: QT_Simulator.h
// Author: h13
// Note: This file is responsible for passing the C + + interface to the C language interface.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	typedef enum
	{
		GhQT_OK = 0,
	} GhQT_Error_t;

	typedef void* GhQT_Simulator_t;

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhQT_Error_t GhQT_SimulatorInit(GhQT_Simulator_t* QT_Simulator);

	GhQT_Error_t GhQT_SimulatorGetResolution(GhQT_Simulator_t* QT_Simulator, int* X_Resolution, int* Y_Resolution);

	GhQT_Error_t GhQT_SimulatorDraw(GhQT_Simulator_t* QT_Simulator);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="QT_Simulator"></param>
	/// <param name="CallbackPtr"></param>
	/// <returns></returns>
	GhQT_Error_t GhQT_SimulatorSetTouchEventsCallback(GhQT_Simulator_t* QT_Simulator, void (*CallbackPtr)(int X, int Y));

	GhQT_Error_t GhQT_SimulatorDestory(GhQT_Simulator_t* QT_Simulator);


#ifdef __cplusplus
}
#endif
