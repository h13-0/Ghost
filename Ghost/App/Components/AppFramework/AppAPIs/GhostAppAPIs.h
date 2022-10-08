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
#include "lvgl.h"

/***********************************Defines************************************/



/***********************************Typedefs***********************************/
#ifdef __cplusplus
EXTREN_C_START
#endif // __cplusplus


/// <summary>
/// 
/// </summary>
typedef void* GhostAppToken_t;


/// <summary>
/// App entry parameters, including token under framework distribution.
/// </summary>
typedef struct
{
	GhostAppToken_t AppToken;
	char* Argv;
} GhostAppArgs_t;


/**********************************Prototypes**********************************/

typedef lv_obj_t* GhostVirtualScreen_t;

/// <summary>
/// App exec handle.
/// According to the specification, this api should be called in the main App thread.
/// The app cannot display the UI and the app status is `GhostAppStatusLoading` 
///		until this function is called.
/// </summary>
/// <param name="AppToken">AppToken in GhostAppArgs_t.</param>
/// <returns>
/// Reason for program exit.
/// </returns>
GhostError_t GhostAppExec(GhostAppToken_t AppToken);


/// <summary>
/// Get virtual screen by AppToken.
/// </summary>
/// <param name="AppToken">AppToken in GhostAppArgs_t.</param>
/// <param name="BackgroundColor">Background color.</param>
/// <returns>
/// Pointer of virtual screen(It's actually a lv_obj_t*).
/// </returns>
lv_obj_t* GhostAppGetVirtualScreen(GhostAppToken_t AppToken, lv_color_t BackgroundColor);


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
