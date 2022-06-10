#include "GhostPlatformConfigs.h"

#include "GhostPermissionManager.h"

GhostError_t GhostPermissionManagerRun(int Argc, void** Args)
{



	return GhostOK;
}

/// <summary>
/// Open the file by the pointer of application info.
///		**After the file is opened, you can use `GhostFS` to operate the file.**
/// </summary>
/// <param name="AppInfoPtr">Pointor of application info.</param>
/// <param name="FilePtr">Pointor of file.</param>
/// <param name="AbsPath">Absolute path of the file to open.</param>
/// <param name="Mode">Mode.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppOpenFile(GhostApplicationInfo_t* AppInfoPtr, GhostFile_t* FilePtr, char* AbsPath, char* Mode)
{
	GhostError_t ret = GhostOK;




	// Get real path.
	if (AppInfoPtr->ApplicationType == GhostNativeApplication)
	{

	}
	else
	{

	}

	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	return GhostOK;
}
