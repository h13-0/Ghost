#pragma once

#include "GhostPlatformErrorDefine.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// Init Ghost clock.
	/// </summary>
	/// <param name=""></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostClockInit(void);

	/// <summary>
	/// Get current Gregorian calendar information.
	/// </summary>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostGetCurrentYear(int* Year);
	GhostError_t GhostGetCurrentMonth(int* Month);
	GhostError_t GhostGetCurrentDay(int* Day);
	GhostError_t GhostGetCurrentDate(int* Year, int* Month, int* Day);

	/// <summary>
	/// Get current time apis.
	/// </summary>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostGetCurrentHour(int* Hour);
	GhostError_t GhostGetCurrentMinute(int* Minute);
	GhostError_t GhostGetCurrentSecond(int* Second);
	GhostError_t GhostGetCurrentTime(int* Hour, int* Minute, int* Second);

	/// <summary>
	/// Get the time from startup to now.
	/// </summary>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostGetCurrentMilliseconds(double* Milliseconds);
	GhostError_t GhostGetCurrentMicroseconds(double* Microseconds);

	/// <summary>
	/// Sleep functions.
	/// </summary>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostSleepMillisecond(int Milliseconds);
	GhostError_t GhostSleepMicrosecond(int Microseconds);

#ifdef __cplusplus
}
#endif
