#pragma once
#include "GhostErrorDefine.h"

GhostError_t GhostAppInit(void);

GhostError_t GhostAppRun(void);

GhostError_t GhostTimerHandler(float TimeIntervalInMillisecond);
