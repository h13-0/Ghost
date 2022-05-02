#include "GhostSafeLVGL.h"

// lvgl mutex.
GhostMutex_t __ghost_lvgl_Mutex__;


/// <summary>
/// Init Ghost safe lvgl.
///		You need to call this API **after lvgl initialization**.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostSafeLV_Init(void)
{
	return GhostMutexInit(&__ghost_lvgl_Mutex__);
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
