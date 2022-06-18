#pragma once
#include "GhostErrorDefine.h"

typedef enum
{
	PlatformModuleNoError = 0,
	PlatformModuleQtError = 1,
	PlatformModuleFS_PatchError = 2,
} PlatformModuleErrorCode;
