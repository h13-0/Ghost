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
 *		his document is used to declare the software layer error ID.
 *
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"

// Standard headers.

// ThirdParty headers.

// Ghost headers.
#include "GhostErrorDefine.h"

/***********************************Defines************************************/


/***********************************Typedefs***********************************/
#ifdef __cplusplus
EXTREN_C_START
#endif // __cplusplus

/// <summary>
/// Declare enum of software error code.
/// </summary>
typedef enum
{
	// No error.
	SoftwareModuleNoError,

	// Components.
	SoftwareModuleSafeLV_Error,
	SoftwareModuleAppFrmError,
	SoftwareModuleAppResPoolError,
	SoftwareModuleThemeFrmError,

	// Native Applications.
	SoftwareModuleLauncherError,
	SoftwareModuleLogMgrError,
	SoftwareModuleThemeMgrError,
	SoftwareModuleThemeError,
} SoftwareModuleErrorCode;

/**********************************Prototypes**********************************/


#ifdef __cplusplus
EXTREN_C_END
#endif // __cplusplus
