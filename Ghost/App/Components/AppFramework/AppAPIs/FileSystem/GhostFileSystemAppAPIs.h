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
 *		This template file is only applicable to visual studio.
 * 
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"

// Standard headers.

// Ghost headers.
#include "GhostErrorDefine.h"

/***********************************Defines************************************/


/***********************************Typedefs***********************************/
EXTREN_C_START


/**********************************Prototypes**********************************/



/// <summary>
/// Open the file by the pointer of application info.
///		**After the file is opened, you can use `GhostFS` to operate the file.**
/// </summary>
/// <param name="AppInfo">Pointor of application info.</param>
/// <param name="FilePtr">Pointor of file.</param>
/// <param name="AbsPath">Absolute path of the file to open.</param>
/// <param name="Mode">Mode.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppOpenFile(const GhostAppInfo_t AppInfo, GhostFile_t* FilePtr, const char* AbsPath, char* Mode);

EXTREN_C_END
