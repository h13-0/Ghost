#pragma once

#include "GhostPlatformErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif
	GhostError_t GhostClockInit(void);

	GhostError_t GhostGetCurrentYear(int* Year);
	GhostError_t GhostGetCurrentMonth(int* Month);
	GhostError_t GhostGetCurrentDay(int* Day);

	GhostError_t GhostGetCurrentDate(int* Year, int* Month, int* Day);

	GhostError_t GhostSleepMillisecond(int Milliseconds);

	GhostError_t GhostSleepMicrosecond(int Microseconds);

	GhostError_t GhostGetCurrentMilliseconds(int* Milliseconds);

	GhostError_t GhostGetCurrentMicroseconds(int* Microseconds);

#ifdef __cplusplus
}
#endif

