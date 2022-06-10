#pragma once

#include "GhostFileSystem.h"
#include "GhostApplicationManager.h"

#ifdef __cplusplus
extern "C" {
#endif

	GhostError_t GhostPermissionManagerRun(int Argc, void** Args);

	/// <summary>
	/// Open the file in the name of app.
	///		**After the file is opened, you can use ghostfs to operate the file.**
	/// </summary>
	/// <param name="Application">Application info.</param>
	/// <param name="File"></param>
	/// <returns></returns>
	GhostError_t GhostAppOpenFile(GhostApplicationInfo_t* Application, GhostFile_t* File, char* Mode);
	

	
#ifdef __cplusplus
}
#endif
