#include "GhostFileSystem.h"

#include "GhostPlatformConfigs.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// rootDirectoryPath will end with '/'.
static char* rootDirectoryPath = NULL;
static int rootDirectoryPathLen = 0;

/// <summary>
/// Init Ghost file system.
/// </summary>
/// <param name="RootDirectoryPath">Path of root directory.</param>
/// <returns></returns>
GhostError_t GhostFS_Init(char* RootDirectoryPath)
{
	char realPath[MacroMaximumPathLength] = { 0 };

#ifdef _WIN32
	if (_fullpath(realPath, RootDirectoryPath, MacroMaximumPathLength) == NULL)
		return GhostErrorFS_PathTooLong;
#else
#error ""
#endif
	rootDirectoryPathLen = strlen(realPath);
	
	// Check the characters at the end of the path.
	if (realPath[rootDirectoryPathLen - 1] == '/')
	{
		// Allocate memory.
		rootDirectoryPath = calloc(1, (rootDirectoryPathLen + 1) * sizeof(char));
		if (rootDirectoryPath == NULL)
			return GhostErrorFS_InitFailed;

		// Copy string.
		memcpy(rootDirectoryPath, realPath, rootDirectoryPathLen * sizeof(char));
	} 
#ifdef _WIN32
	else if (realPath[rootDirectoryPathLen - 1] == '\\')
	{
		// Allocate memory.
		rootDirectoryPath = calloc(1, (rootDirectoryPathLen + 1) * sizeof(char));
		if (rootDirectoryPath == NULL)
			return GhostErrorFS_InitFailed;

		// Copy string.
		memcpy(rootDirectoryPath, realPath, rootDirectoryPathLen * sizeof(char));
	}
#endif
	else {
		// Add '/' to end.
		rootDirectoryPathLen++;

		// Allocate memory.
		rootDirectoryPath = calloc(1, (rootDirectoryPathLen + 1) * sizeof(char));
		if (rootDirectoryPath == NULL)
			return GhostErrorFS_InitFailed;

		// Copy string.
		memcpy(rootDirectoryPath, realPath, rootDirectoryPathLen * sizeof(char));

#ifdef _WIN32
		* (rootDirectoryPath + rootDirectoryPathLen - 1) = '\\';
#else
		* (rootDirectoryPath + rootDirectoryPathLen - 1) = '/';
#endif
		
	}

#ifdef _WIN32
	// Replace '/' to '\\'.
	for (int index = 0; index < rootDirectoryPathLen; index++)
	{
		//The delimiter of windows is FUCKING PIECE OF SHIT!
		if (*(rootDirectoryPath + index) == '/')
			*(rootDirectoryPath + index) = '\\';
	}
#endif

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

static GhostError_t getRealFilePath(const char* AbsPath, char* RealPath, int MaximumPathLength)
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
	char* realPath = calloc(1, sizeof(char) * MacroMaximumPathLength + rootDirectoryPathLen);
	if (realPath == NULL)
		return GhostErrorFS_OutOfMemory;

	/// Strcat string.
	if (*(FilePath) == '/')
	{
		// Absolute path.
		// Omit duplicate characters '/'.
		memcpy(realPath, rootDirectoryPath, rootDirectoryPathLen);
		memcpy(realPath + rootDirectoryPathLen, FilePath + 1, strlen(FilePath - 1));
	}
	else if (*(FilePath) == '.')
	{
		// Relative path.
		// Copy rootDirectoryPath to the begining.
		memcpy(realPath, rootDirectoryPath, rootDirectoryPathLen);
		memcpy(realPath + rootDirectoryPathLen, FilePath, strlen(FilePath));
	}
	else {
		// Illegal path.
		return GhostErrorFS_PathIllegal;
	}

	GhostError_t ret = getRealFilePath(realPath, realPath, MacroMaximumPathLength + rootDirectoryPathLen);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Check whether the path is legal.
	int minimumPath = 0;
	if (rootDirectoryPathLen < strlen(realPath))
		minimumPath = rootDirectoryPathLen;
	else
		minimumPath = strlen(realPath);

	if (memcmp(rootDirectoryPath, realPath, minimumPath))
	{
		// Above the root path, access denied.
		printf("%s", rootDirectoryPath);
		return GhostErrorFS_PathIllegal;
	}

	// Create mutex for file.
	ret = GhostMutexInit(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Lock mutex.
	ret = GhostMutexLock(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Open file.
	GhostFile->FileStream = fopen(realPath, Mode);

	/// Free memory.
	free(realPath);

	// Check whether the file was successfully opened.
	if (GhostFile->FileStream == NULL)
		return GhostErrorFS_FileOpenFailed;

	// Unlock mutex.
	ret = GhostMutexUnlock(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	return GhostOK;
}

/// <summary>
/// Flush buffer to file.
/// </summary>
/// <param name="GhostFile"></param>
/// <returns></returns>
GhostError_t GhostFS_Flush(GhostFile_t* GhostFile)
{
	// Check file handle.
	if (GhostFile == NULL)
		return GhostErrorFS_FileUninitialized;

	// Lock mutex.
	GhostError_t ret = GhostMutexLock(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Flush.
	if (fflush(GhostFile->FileStream))
		return GhostErrorFS_FileFlushFailed;

	// Check whether the file was successfully opened.
	if (GhostFile->FileStream == NULL)
		return GhostErrorFS_FileOpenFailed;

	// Unlock mutex.
	ret = GhostMutexUnlock(&GhostFile->Mutex);
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
	// Check file handle.
	if (GhostFile == NULL)
		return GhostErrorFS_FileUninitialized;

	// Lock mutex.
	GhostError_t gret = GhostMutexLock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return gret;

	int ret = fclose(GhostFile->FileStream);

	// Unlock mutex.
	gret = GhostMutexUnlock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return gret;

	if (!ret)
	{
		// Delete Mutex.
		GhostMutexDestroy(&GhostFile->Mutex);
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
/// Read file stream.
/// </summary>
/// <param name="BufferPtr">Pointor of buffer.</param>
/// <param name="Size">Size of data.</param>
/// <param name="Count">Count of data.</param>
/// <param name="GhostFile">Pointor of file.</param>
/// <returns>ame as fread, equal to the data size actually read.</returns>
int GhostFS_Read(void* BufferPtr, size_t Size, size_t Count, GhostFile_t* GhostFile)
{
	// Check file handle.
	if (GhostFile == NULL)
		return 0;

	// Lock mutex.
	GhostError_t gret = GhostMutexLock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;

	// Write.
	int ret = fread(BufferPtr, Size, Count, GhostFile->FileStream);

	// Unlock mutex.
	gret = GhostMutexUnlock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;

	return ret;
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
	// Check file handle.
	if (GhostFile == NULL)
		return 0;

	// Lock mutex.
	GhostError_t gret = GhostMutexLock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;

	// Write.
	int ret = fwrite(BufferPtr, Size, Count, GhostFile->FileStream);

	// Unlock mutex.
	gret = GhostMutexUnlock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;

	return ret;
}

/// <summary>
/// Get file size.
/// </summary>
/// <param name="GhostFile">Pointor of file.</param>
/// <returns>File size in size_t.</returns>
size_t GhostFS_GetFileSize(GhostFile_t* GhostFile)
{
	// Check file handle.
	if (GhostFile == NULL)
		return 0;

	// Lock mutex.
	GhostError_t gret = GhostMutexLock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;

	// Calculate file size.
	fseek(GhostFile->FileStream, 0, SEEK_END);
	size_t size = ftell(GhostFile->FileStream);
	
	// Unlock mutex.
	gret = GhostMutexUnlock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;
	
	return size;
}

/// <summary>
/// Splice path.
///		You need to manually use the `free` function to free memory after the path is used.
/// </summary>
/// <param name="ParentPath">Parent path in char*.</param>
/// <param name="Subpath">Subpath in char*.</param>
char* GhostFS_Join(char* ParentPath, char* Subpath)
{
	GhostError_t ret = GhostOK;
	
	int length = 0;
	int subpathLength = 0;
	char* temp = NULL;
	
	// Splice string.
	length = strlen(ParentPath);
	subpathLength = strlen(Subpath);
	if(*(ParentPath + strlen(ParentPath) - 1) != '/')
	{
		if (*(Subpath) != '/')
		{
			temp = calloc(1, sizeof(char) * (length + subpathLength + 2));
			memcpy(temp, ParentPath, length);
			*(temp + length) = '/';
			memcpy(temp + length + 1, Subpath, subpathLength);
			length = length + subpathLength + 1;
		}
		else {
			temp = calloc(1, sizeof(char) * (length + subpathLength + 1));
			memcpy(temp, ParentPath, length);
			memcpy(temp + length, Subpath, subpathLength);
			length = length + subpathLength;
		}
	}
	else {
		if (*(Subpath) != '/')
		{
			temp = calloc(1, sizeof(char) * (length + subpathLength + 1));
			memcpy(temp, ParentPath, length);
			memcpy(temp + length, Subpath, subpathLength);
			length = length + subpathLength;
		}
		else {
			temp = calloc(1, sizeof(char) * (length + subpathLength));
			memcpy(temp, ParentPath, length);
			memcpy(temp + length, Subpath + 1, subpathLength - 1);
			length = length + subpathLength - 1;
		}
	}

	// Calculate real path.
	char* result = calloc(1, sizeof(char)*MacroMaximumPathLength);
	return temp;
	
	ret = getRealFilePath(temp, result, MacroMaximumPathLength);
	if(ret.LayerErrorCode != GhostNoError)
	{
		free(result);
		return NULL;
	}
	return result;
}


