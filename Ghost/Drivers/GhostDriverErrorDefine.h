#pragma once
#include "GhostErrorDefine.h"

typedef enum
{
	DriverModuleNoError          = 0,
	DriverModuleClockError       = 1,
	DriverModuleFileSystemError  = 2,
	DriverModuleThreadError      = 3,
	DriverModuleScreenError      = 4,
	DriverModuleTouchScreenError = 5,
} DriverModuleErrorCode;
