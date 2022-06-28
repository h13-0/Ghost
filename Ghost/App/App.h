#pragma once
#include "GhostErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

	GhostError_t GhostAppInit(void);

	GhostError_t GhostAppRun(void);

	typedef enum
	{
		GhostRunning = 0,
		GhostUninitialized = 1,
	} GhostStatus_t;

	GhostStatus_t GhostAppStatus(void);

	GhostError_t GhostTimerHandler(float TimeIntervalInMillisecond);

	GhostError_t GhostPowerOff(void);


#ifdef __cplusplus
}
#endif
