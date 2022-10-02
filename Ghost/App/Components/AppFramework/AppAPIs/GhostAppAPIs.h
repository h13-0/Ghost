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
 *		NativeApp is only allowed to use the API declared in this file, all 
 *		security APIs in the standard library, and apis in all the following 
 *		header files:
 *			cJSON.h
 *
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"

// Standard headers.

// 

// Ghost headers.
#include "GhostErrorDefine.h"

// Thirdparty headers.
#include "cJSON.h"

/***********************************Defines************************************/



/***********************************Typedefs***********************************/
#ifdef __cplusplus
EXTREN_C_START
#endif // __cplusplus

typedef void* GhostAppToken_t;

/// <summary>
/// App entry parameters, including token under framework distribution.
/// </summary>
typedef struct
{
	GhostAppToken_t AppToken;
	int Argc;
	char* Argv[];
} GhostAppArgs_t;


/**********************************Prototypes**********************************/

typedef lv_obj_t GhostVirtualScreen_t;

/// <summary>
/// 
/// According to the specification, this api should be called in the main App thread.
/// </summary>
/// <param name="AppToken"></param>
/// <returns></returns>
GhostError_t GhostAppExec(GhostAppToken_t AppToken);


/// <summary>
/// Get virtual screen by the pointer of application info.
/// </summary>
/// <param name="AppInfoPtr">Pointor of application info.</param>
/// <param name="ScreenPtr">Pointor of virtual screen.(pointor to lv_obj_t*)</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppGetVirtualScreen(GhostAppToken_t AppToken, lv_obj_t** const ScreenPtr);


/// <summary>
/// 
/// </summary>
/// <param name="AppInfoPtr"></param>
/// <param name="Code"></param>
/// <returns></returns>
GhostError_t GhostAppIsForeGround(GhostAppToken_t AppToken);

//GhostError_t GhostAppGet



#ifdef __cplusplus
EXTREN_C_END
#endif // __cplusplus
