#pragma once
#include "GhostSoftwareErrorDefine.h"

#include "safe_lvgl.h"

/// Declare Ghost_LV error.


/// You need to call all APIs of this header file **after lvgl initialization**.

#ifdef __cplusplus
extern "C" {
#endif

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
	/// Lock lvgl mutex.
	///		You need to call this API **after lvgl initialization**.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhostError_t GhostLV_Lock(void);

	/// <summary>
	/// Unlock lvgl mutex.
	///		You need to call this API **after lvgl initialization**.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhostError_t GhostLV_Unlock(void);

	/// <summary>
	/// Try lock lvgl mutex.
	///		You need to call this API **after lvgl initialization**.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhostError_t GhostLV_TryLock(void);

#ifdef __cplusplus
}
#endif
