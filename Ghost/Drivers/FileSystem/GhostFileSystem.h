#pragma once

#include "GhostDriverErrorDefine.h"

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
#define GhostErrorFS_InitFailed        DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 1)
#define GhostErrorFS_FileNotFound      DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 2)
#define GhostErrorFS_PathTooLong       DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 3)

	/// <summary>
	/// Init Ghost file system.
	/// </summary>
	/// <param name="RootDirectoryPath">Path of root directory.</param>
	/// <returns></returns>
	GhostError_t GhostFS_Init(char* RootDirectoryPath);

	/// <summary>
	/// De init Ghost file system.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhostError_t GhostFS_DeInit(void);

	/// <summary>
	/// Open file.
	/// </summary>
	/// <param name="FilePath">Similar to the Linux style path starting from the root directory "/".</param>
	/// <param name="FilePtr">Pointor of file.</param>
	/// <param name="Mode">Mode.</param>
	/// <returns></returns>
	GhostError_t GhostFS_Open(char* FilePath, FILE* FilePtr, char* Mode);

#ifdef __cplusplus
}
#endif
