#pragma once
#include "GhostErrorDefine.h"

typedef enum
{
	DriverModuleNoError            = 0,
	DriverModuleMemoryManagerError = 1,
	DriverModuleThreadError        = 2,
	DriverModuleLogError           = 3,
	DriverModuleClockError         = 4,
	DriverModuleFileSystemError    = 5,
	DriverModuleScreenError        = 6,
	DriverModuleTouchScreenError   = 7,
} DriverModuleErrorCode;
