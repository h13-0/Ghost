#pragma once

#include "GhostDriverErrorDefine.h"

#include <stdio.h>

#include "GhostThread.h"

#define GhostErrorFS_InitFailed             DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 1)
#define GhostErrorFS_Uninitialized          DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 2)
#define GhostErrorFS_MountPointNotExist     DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 3)
#define GhostErrorFS_FileNotFound           DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 4)
#define GhostErrorFS_PathTooLong            DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 5)
#define GhostErrorFS_PathIllegal            DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 6)
#define GhostErrorFS_FileOpenFailed         DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 7)
#define GhostErrorFS_OutOfMemory            DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 8)
#define GhostErrorFS_CloseFailed            DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 9)
#define GhostErrorFS_HandleInvalid          DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 10)
#define GhostErrorFS_FileUninitialized      DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 11)
#define GhostErrorFS_FileFlushFailed        DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 12)
#define GhostErrorFS_SeekFailed             DeclareGhostError(GhostDriverLayerError, DriverModuleFileSystemError, 13)

#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// Typedef Ghost file.
	/// </summary>
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
	GhostError_t GhostFS_Init(const char* RootDirectoryPath);

  
	/// <summary>
	/// De init Ghost file system.
	/// </summary>
	/// <param name=""></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_DeInit(void);


	/// <summary>
	/// Initializing file system support for lvgl.
	///		This function MUST be called AFTER `lv_init` and `GhostFS_Init`.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhostError_t GhostLVGL_FS_Init(void);
  

	/// <summary>
	/// Get the real path of the file.
	/// </summary>
	/// <param name="AbsPath">Path from mount directory.</param>
	/// <param name="RealPath">Real path, this variable requires manual memory allocation.</param>
	/// <param name="RealPathBufferLength">Buffer size of real path.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_GetRealPath(const char* AbsPath, char* RealPath, int RealPathBufferLength);

  
	/// <summary>
	/// Open file.
	/// </summary>
	/// <param name="FilePath">Similar to the Linux style path starting from the root directory "/".</param>
	/// <param name="GhostFile">Pointor to file.</param>
	/// <param name="Mode">Mode.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_Open(const char* FilePath, GhostFile_t* GhostFile, const char* Mode);

  
	/// <summary>
	/// Flush buffer to file.
	/// </summary>
	/// <param name="GhostFile"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_Flush(const GhostFile_t* GhostFile);

	/// <summary>
	/// Close file.
	/// </summary>
	/// <param name="GhostFile">Pointor to file.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_Close(GhostFile_t* GhostFile);

  
	/// <summary>
	/// Read file stream.
	/// </summary>
	/// <param name="BufferPtr">Pointor to buffer.</param>
	/// <param name="Size">Size of data.</param>
	/// <param name="Count">Count of data.</param>
	/// <param name="GhostFile">Pointor to file.</param>
	/// <returns>Same as fread, equal to the data size actually read.</returns>
	int GhostFS_Read(void* BufferPtr, size_t Size, size_t Count, const GhostFile_t* GhostFile);

  
	/// <summary>
	/// Write file stream.
	/// </summary>
	/// <param name="BufferPtr">Pointor to buffer.</param>
	/// <param name="Size">Size of data.</param>
	/// <param name="Count">Count of data.</param>
	/// <param name="GhostFile">Pointor to file.</param>
	/// <returns>Same as fwrite, equal to the data size actually written.</returns>
	int GhostFS_Write(const void* BufferPtr, size_t Size, size_t nmemb, const GhostFile_t* GhostFile);


	/// <summary>
	/// Typedef of GhostFS_Whence_t, value equivalent to parameter `whence` in fseek.
	/// </summary>
	typedef enum
	{
		GhostFS_SeekFromStart   = 0x00,
		GhostFS_SeekFromCurrent = 0x01,
		GhostFS_SeekFromEnd     = 0x02,
	} GhostFS_Whence_t;


	/// <summary>
	/// File offset(seek).
	/// </summary>
	/// <param name="GhostFile">Pointor to file.</param>
	/// <param name="Offset">Offset.</param>
	/// <param name="Whence">Offset start position.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostFS_Seek(const GhostFile_t* GhostFile, long int Offset, GhostFS_Whence_t Whence);


	/// <summary>
	/// Returns the current file pointer position(ftell).
	/// </summary>
	/// <param name="GhostFile">Pointor to file.</param>
	/// <returns>Same as ftell, return -1L if failed.</returns>
	long int GhostFS_Tell(const GhostFile_t* GhostFile);


	/// <summary>
	/// Get file size.
	/// </summary>
	/// <param name="GhostFile">Pointor to file.</param>
	/// <returns>File size in size_t.</returns>
	size_t GhostFS_GetFileSize(const GhostFile_t* GhostFile);

  
	/// <summary>
	/// Splice path.
	///		You need to manually use the `free` function to free memory after the path is used.
	/// </summary>
	/// <param name="ParentPath">Parent path in char*.</param>
	/// <param name="Subpath">Subpath in char*.</param>
	/// <returns>Pointor to result.</returns>
	/// TODO: Change function result parameter transfer method.
	char* GhostFS_Join(const char* ParentPath, const char* Subpath);


	/// <summary>
	/// Typedef of GhostFolder.
	/// </summary>
	typedef struct
	{
		//GhostFolderPatch_t Folder;
		GhostMutex_t Mutex;
	} GhostFolder_t;


#ifdef __cplusplus
}
#endif
