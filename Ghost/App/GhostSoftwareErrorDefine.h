#pragma once
#include "GhostErrorDefine.h"

/// <summary>
/// Declare enum of software error code.
/// </summary>
typedef enum
{
	SoftwareModuleNoError         = 0,
	SoftwareModuleAppMgrError     = 1,
	SoftwareModuleLauncherError   = 2,
	SoftwareModuleGhostLogError   = 3,
	SoftwareModuleSafeLV_Error    = 4,
} SoftwareModuleErrorCode;
