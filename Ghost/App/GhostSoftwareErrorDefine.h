#pragma once
#include "GhostErrorDefine.h"

/// <summary>
/// Declare enum of software error code.
/// </summary>
typedef enum
{
	SoftwareModuleNoError         = 0,
	SoftwareModuleLogError        = 1,
	SoftwareModuleAppMgrError     = 2,
	SoftwareModuleLauncherError   = 3,
	SoftwareModuleGhostLogError   = 4,
	SoftwareModuleSafeLV_Error    = 5,
	SoftwareModuleThemeMgrError   = 6,
} SoftwareModuleErrorCode;
