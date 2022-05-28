#pragma once
#include "GhostErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif
	GhostError_t GhostAppRun(void);

	GhostError_t GhostTimerHandler(float TimeIntervalInMillisecond);

	GhostError_t GhostPowerOff(void);

#ifdef __cplusplus
}
#endif
