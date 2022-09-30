/*******************************************************************************
 * @File   : $safeitemname$
 * @Path   : $rootnamespace$
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
// Self headers.

// Standard headers.

// ThirdParty headers.

// Ghost headers.


/***********************************Defines************************************/



/***********************************Typedefs***********************************/


/**********************************Prototypes**********************************/



/// <summary>
/// Open the file by the pointer of application info.
///		**After the file is opened, you can use `GhostFS` to operate the file.**
/// </summary>
/// <param name="AppInfoPtr">Pointor of application info.</param>
/// <param name="FilePtr">Pointor of file.</param>
/// <param name="AbsPath">Absolute path of the file to open.</param>
/// <param name="Mode">Mode.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppOpenFile(const GhostAppInfo_t const AppInfoPtr, GhostFile_t* FilePtr, const char* AbsPath, char* Mode)
{
	//


	if (AppInfoPtr->ApplicationType == GhostNativeApplication)
	{
		// TODO: Check Mode and path.

		// Open file.
		GhostLogTerminateIfErr(Error, GhostFS_Open(AbsPath, FilePtr, Mode));
	}
	else
	{
#if(MacroAllowRoot)
		// Check whether it is a root user.
		// TODO:




#endif

		// Get real path.
		char realPath[MacroMaximumPathLength] = { '\0' };
		GhostLogTerminateIfErr(Error, GhostFS_GetRealPath(AbsPath, realPath, MacroMaximumPathLength));

		// Check whether the path is legal.
	}

	return GhostOK;
}
