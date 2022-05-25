#include "GhostSafeLVGL.h"
#include "GhostThread.h"

// lvgl mutex.
GhostMutex_t lvglMutex;

/// <summary>
/// Init Ghost safe lvgl.
///		You need to call this API **after lvgl initialization**.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostSafeLV_Init(void)
{
	return GhostMutexInit(&lvglMutex);
}

/// <summary>
/// Safe lvgl heartbeat function interface.
/// 	You need to call this API **after lvgl initialization**.
/// </summary>
/// <param name="HeartbeatPeriod">Heartbeat period in millisecond.</param>
/// <returns></returns>
GhostError_t GhostSafeLV_HeartBeat(int HeartbeatPeriod)
{
	LV_Safe(
		lv_tick_inc(HeartbeatPeriod);
		lv_timer_handler();
	)
	return GhostOK;
}

/// <summary>
/// Lock lvgl mutex.
///		You need to call this API **after lvgl initialization**.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostLV_Lock(void)
{
	return GhostMutexLock(&lvglMutex);
}

/// <summary>
/// Unlock lvgl mutex.
///		You need to call this API **after lvgl initialization**.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostLV_Unlock(void)
{
	return GhostMutexUnlock(&lvglMutex);
}
