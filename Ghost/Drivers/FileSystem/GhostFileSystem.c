#include "GhostFileSystem.h"

#include "GhostPlatformConfigs.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char* rootDirectoryPath = NULL;
static int rootDirectoryPathLen = 0;

/// <summary>
/// Init Ghost file system.
/// </summary>
/// <param name="RootDirectoryPath">Path of root directory.</param>
/// <returns></returns>
GhostError_t GhostFS_Init(char* RootDirectoryPath)
{
	rootDirectoryPathLen = strlen(RootDirectoryPath);
	rootDirectoryPath = malloc(rootDirectoryPathLen * sizeof(char));
	if (rootDirectoryPath == NULL)
		return GhostErrorFS_InitFailed;

	memcpy(rootDirectoryPath, RootDirectoryPath, rootDirectoryPathLen * sizeof(char));
	return GhostOK;
}

/// <summary>
/// De init Ghost file system.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostFS_DeInit(void)
{
	free(rootDirectoryPath);
	return GhostOK;
}

static GhostError_t getRealFilePath(char* AbsPath, char* RealPath, int MaximumPathLength)
{
	if (strlen(AbsPath) > MacroMaximumPathLength)
	{
		return GhostErrorFS_PathTooLong;
	}
	else {
#ifdef _WIN32
		if (_fullpath(RealPath, AbsPath, MaximumPathLength) == NULL)
			return GhostErrorFS_PathTooLong;
#else
#error "TODO in linux."
#endif
		return GhostOK;
	}
}

/// <summary>
/// Open file.
/// </summary>
/// <param name="FilePath">Similar to the Linux style path starting from the root directory "/".</param>
/// <param name="GhostFile">Pointor of file.</param>
/// <param name="Mode">Mode.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostFS_Open(const char* FilePath, GhostFile_t* GhostFile, char* Mode)
{
	// Get real path.
	/// Allocate memory.
	char* realPath = malloc(sizeof(char) * MacroMaximumPathLength + rootDirectoryPathLen);
	if (realPath == NULL)
		return GhostErrorFS_OutOfMemory;

	GhostError_t ret = getRealFilePath(FilePath, realPath, MacroMaximumPathLength + rootDirectoryPathLen);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Create mutex for file.
	ret = GhostMutexCreate(GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Lock mutex.
	ret = GhostMutexLock(GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	GhostFile->FileStream = fopen(realPath, Mode);

	/// Free memory.
	free(realPath);

	// Check whether the file was successfully opened.
	if (GhostFile->FileStream == NULL)
		return GhostErrorFS_FileOpenFailed;

	// Unlock mutex.
	ret = GhostMutexUnlock(GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	return GhostOK;
}

/// <summary>
/// Close file.
/// </summary>
/// <param name="GhostFile">Pointor of file.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostFS_Close(GhostFile_t* GhostFile)
{
	if (GhostFile == NULL)
		return GhostErrorFS_HandleInvalid;

	// Lock mutex.
	GhostError_t gret = GhostMutexLock(GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return gret;

	int ret = fclose(GhostFile->FileStream);

	// Unlock mutex.
	gret = GhostMutexUnlock(GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return gret;

	if (!ret)
	{
		// Delete Mutex.
		GhostMutexDelete(GhostFile->Mutex);
		GhostFile = NULL;
		return GhostOK;
	}
	else {
		// TODO: log.
		//perror("fclose");
		return GhostErrorFS_CloseFailed;
	}
}

/// <summary>
/// Write file stream.
/// </summary>
/// <param name="BufferPtr">Pointor of buffer.</param>
/// <param name="Size">Size of data.</param>
/// <param name="Count">Count of data.</param>
/// <param name="GhostFile">Pointor of file.</param>
/// <returns>Same as fwrite, equal to the data size actually written.</returns>
int GhostFS_Write(void* BufferPtr, size_t Size, size_t Count, GhostFile_t* GhostFile)
{
	// Lock mutex.
	GhostError_t gret = GhostMutexLock(GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;

	int ret = fwrite(BufferPtr, Size, Count, GhostFile->FileStream);

	// Unlock mutex.
	gret = GhostMutexUnlock(GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;

	return ret;
}


