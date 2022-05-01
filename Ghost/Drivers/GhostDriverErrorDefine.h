#pragma once
#include "GhostErrorDefine.h"

typedef enum
{
	DriverModuleNoError          = 0,
	DriverModuleClockError       = 1,
	DriverModuleFileSystemError  = 2,
	DriverModuleScreenError      = 3,
	DriverModuleTouchScreenError = 4,
} DriverModuleErrorCode;
