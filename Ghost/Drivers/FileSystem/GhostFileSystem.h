#pragma once

#include "GhostDriverErrorDefine.h"

#include <stdio.h>

#include "GhostThread.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GhostErrorFS_InitFailed        DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 1)
#define GhostErrorFS_FileNotFound      DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 2)
#define GhostErrorFS_PathTooLong       DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 3)
#define GhostErrorFS_FileOpenFailed    DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 4)
#define GhostErrorFS_OutOfMemory       DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 5)
#define GhostErrorFS_CloseFailed       DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 6)
#define GhostErrorFS_HandleInvalid     DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 7)

	typedef struct
	{
		FILE* FileStream;
		GhostMutex_t Mutex;
	} GhostFile_t;

	/// <summary>
	/// Init Ghost file system.
	/// </summary>
	/// <param name="RootDirectoryPath">Path of root directory.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_Init(char* RootDirectoryPath);

	/// <summary>
	/// De init Ghost file system.
	/// </summary>
	/// <param name=""></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_DeInit(void);

	/// <summary>
	/// Open file.
	/// </summary>
	/// <param name="FilePath">Similar to the Linux style path starting from the root directory "/".</param>
	/// <param name="GhostFile">Pointor of file.</param>
	/// <param name="Mode">Mode.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_Open(const char* FilePath, GhostFile_t* GhostFile, char* Mode);

	GhostError_t GhostFS_Flush(GhostFile_t* GhostFile);

	/// <summary>
	/// Close file.
	/// </summary>
	/// <param name="GhostFile">Pointor of file.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_Close(GhostFile_t* GhostFile);

	/// <summary>
	/// Write file stream.
	/// </summary>
	/// <param name="BufferPtr">Pointor of buffer.</param>
	/// <param name="Size">Size of data.</param>
	/// <param name="Count">Count of data.</param>
	/// <param name="GhostFile">Pointor of file.</param>
	/// <returns>Same as fwrite, equal to the data size actually written.</returns>
	int GhostFS_Write(void* BufferPtr, size_t Size, size_t nmemb, GhostFile_t* GhostFile);


#ifdef __cplusplus
}
#endif
