#pragma once

#include "GhostPlatformErrorDefine.h"

#define GhostErrorFS_PatchFileNotExist                     DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 1)
#define GhostErrorFS_PatchPathNotExist                     DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 2)
#define GhostErrorFS_PatchIsNotFile                        DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 3)
#define GhostErrorFS_PatchIsNotFolder                      DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 4)
#define GhostErrorFS_PathPathTooLong                       DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 5)
#define GhostErrorFS_PatchPermissionDenied                 DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 6)

#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// Get the real path of the file.
	/// </summary>
	/// <param name="AbsPath">Path from mount directory.</param>
	/// <param name="RealPath">Real path, this variable requires manual memory allocation.</param>
	/// <param name="RealPathBufferLength">Buffer size of real path.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFSP_GetRealPath(const char* AbsPath, char* RealPath, size_t RealPathBufferLength);

	/// <summary>
	/// Check whether the file exists.
	///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
	/// </summary>
	/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
	/// <returns>GhostOK is returned when the file exists.</returns>
	GhostError_t GhostFSP_IsFileExist(const char* RealPath);

	/// <summary>
	/// Check whether the folder exists.
	///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
	/// </summary>
	/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
	/// <returns></returns>
	GhostError_t GhostFSP_IsFolderExist(const char* RealPath);

	/// <summary>
	/// Check if the path is a file.
	///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
	/// </summary>
	/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
	/// <returns></returns>
	GhostError_t GhostFSP_IsFile(const char* RealPath);

	/// <summary>
	/// Check if the path is a folder.
	///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
	/// </summary>
	/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
	/// <returns></returns>
	GhostError_t GhostFSP_IsFolder(const char* RealPath);

#ifdef __cplusplus
}
#endif
