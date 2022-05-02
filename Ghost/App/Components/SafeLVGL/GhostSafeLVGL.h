#pragma once
#include "GhostSoftwareErrorDefine.h"

#include "GhostThread.h"
#include "lvgl.h"

/// You need to call all APIs of this header file **after lvgl initialization**.

/// <summary>
/// Init Ghost safe lvgl.
///		You need to call this API **after lvgl initialization**.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostSafeLV_Init(void);

/// <summary>
/// Safe lvgl heartbeat function interface.
/// 	You need to call this API **after lvgl initialization**.
/// </summary>
/// <param name="HeartbeatPeriod">Heartbeat period in millisecond.</param>
/// <returns></returns>
GhostError_t GhostSafeLV_HeartBeat(int HeartbeatPeriod);

/// <summary>
/// 
/// </summary>
extern GhostMutex_t __ghost_lvgl_Mutex__;

/// <summary>
/// Do functions with lvgl mutex.
/// </summary>
/// <param name="">Functions.</param>
#define LV_Safe(functions) \
	GhostMutexLock(&__ghost_lvgl_Mutex__); \
	functions; \
	GhostMutexUnlock(&__ghost_lvgl_Mutex__); \
