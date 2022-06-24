#pragma once

#include "GhostPlatformErrorDefine.h"

#include <stddef.h>

#define GhostErrorFS_PatchPermissionDenied                 DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 1)
#define GhostErrorFS_PatchIsNotFile                        DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 2)
#define GhostErrorFS_PatchIsNotFolder                      DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 3)
#define GhostErrorFS_PatchPathTooLong                      DeclareGhostError(GhostPlatformLayerError, PlatformModuleFS_PatchError, 4)

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
	/// Typedef of AccessMode:
	///		04 check read permission.
	///		02 check write permission.
	///		01 check execution authority.
	///		00 checking the existence of files.
	/// </summary>
	typedef enum
	{
		GhostFSP_Exist      = 0,
		GhostFSP_Executable = (1 << 0),
		GhostFSP_Writable   = (1 << 1),
		GhostFSP_Readable   = (1 << 2),
		GhostFSP_ReadWriteable = GhostFSP_Writable | GhostFSP_Readable,
	} GhostFSP_AccessMode_t;


	/// <summary>
	/// Check whether this program has access to files or folders.
	///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
	/// </summary>
	/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
	/// <param name="AccessMode">AccessMode.</param>
	/// <returns>GhostOK is returned when the file exists.</returns>
	GhostError_t GhostFSP_Access(const char* RealPath, GhostFSP_AccessMode_t AccessMode);


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


	/// <summary>
	/// Typedef of GhostFolderPatch(`DIR*`)
	/// </summary>
	typedef void* GhostFolderPatch_t;



#ifdef __cplusplus
}
#endif
