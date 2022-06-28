#pragma once

// This library is only a platform interface library and does not require thread safety.

#include "GhostPlatformErrorDefine.h"

#include <stddef.h>

#if _WIN32
#include <Windows.h>
#elif __linux__

#endif

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
	/// Typedef of GhostFolderPatch(`DIR*`).
	/// </summary>
#if _WIN32
	typedef struct
	{
		int a;
	} GhostFolderPatch_t;
#elif __linux__ 

#endif


	/// <summary>
	/// Open folder by real path.
	///		This function is **NON thread safe**.
	/// </summary>
	/// <param name="Folder">Pointor to folder.</param>
	/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
	/// <returns></returns>
	GhostError_t GhostFSP_FolderOpen(GhostFolderPatch_t* Folder, const char* RealPath);


	/// <summary>
	/// Close folder.
	///		This function is **NON thread safe**.
	/// </summary>
	/// <param name="Folder">Pointor to folder.</param>
	/// <returns></returns>
	GhostError_t GhostFSP_FolderClose(const GhostFolderPatch_t* Folder);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="Folder">Pointor to folder.</param>
	/// <returns></returns>
	GhostError_t GhostFSP_FolderRead(const GhostFolderPatch_t* Folder);

#ifdef __cplusplus
}
#endif
