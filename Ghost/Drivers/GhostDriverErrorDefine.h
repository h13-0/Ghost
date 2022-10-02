#pragma once
/*******************************************************************************
 * @File   : $safeitemname$.h
 * @Path   : $rootnamespace$/$safeitemname$.h
 * @Module :
 *
 * @Author : $username$
 * @Time   : $time$
 * @license: AGPL-3.0(https://github.com/h13-0/Ghost/blob/master/LICENSE)
 * @Notes  :
 *		This document is used to declare the driver layer error ID.
 *
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
// #include "GhostPlatformConfigs.h"

// Standard headers.

// ThirdParty headers.

// Ghost headers.
#include "GhostErrorDefine.h"

/***********************************Defines************************************/

/***********************************Typedefs***********************************/
#ifdef __cplusplus
EXTREN_C_START
#endif // __cplusplus

typedef enum
{
	DriverModuleNoError,
	DriverModuleMemoryManagerError,
	DriverModuleThreadError,
	DriverModuleMutexError,
	DriverModuleLogError,
	DriverModuleClockError,
	DriverModuleFileSystemError,
	DriverModuleScreenError,
	DriverModuleTouchScreenError,
} DriverModuleErrorCode;

/**********************************Prototypes**********************************/

#ifdef __cplusplus
EXTREN_C_END
#endif // __cplusplus
