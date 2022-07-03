#include "GhostFileSystem.h"

#include "GhostPlatformConfigs.h"

#include "GhostFileSystemPatch.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lvgl.h"

// rootDirectoryPath will end with '/'.
static char* rootDirectoryPath = NULL;
static int rootDirectoryPathLen = 0;
static bool ghostFS_Inited = false;

// lvgl port functions.
static void* fs_open(lv_fs_drv_t* drv, const char* path, lv_fs_mode_t mode);
static lv_fs_res_t fs_close(lv_fs_drv_t* drv, void* file_p);
static lv_fs_res_t fs_read(lv_fs_drv_t* drv, void* file_p, void* buf, uint32_t btr, uint32_t* br);
static lv_fs_res_t fs_write(lv_fs_drv_t* drv, void* file_p, const void* buf, uint32_t btw, uint32_t* bw);
static lv_fs_res_t fs_seek(lv_fs_drv_t* drv, void* file_p, uint32_t pos, lv_fs_whence_t whence);
static lv_fs_res_t fs_tell(lv_fs_drv_t* drv, void* file_p, uint32_t* pos_p);

static void* fs_dir_open(lv_fs_drv_t* drv, const char* path);
static lv_fs_res_t fs_dir_read(lv_fs_drv_t* drv, void* rddir_p, char* fn);
static lv_fs_res_t fs_dir_close(lv_fs_drv_t* drv, void* rddir_p);

/// <summary>
/// Init Ghost file system.
/// </summary>
/// <param name="RootDirectoryPath">Path of root directory.</param>
/// <returns></returns>
GhostError_t GhostFS_Init(const char* RootDirectoryPath)
{
	char realPath[MacroMaximumPathLength] = { 0 };

#ifdef _WIN32
	if (_fullpath(realPath, RootDirectoryPath, MacroMaximumPathLength) == NULL)
		return GhostErrorFS_PathTooLong;
#else
#error ""
#endif

	rootDirectoryPathLen = (int)strlen(realPath);
	
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

	// Check whether the file system is mounted.
	if (IfGhostError(GhostFSP_Access(rootDirectoryPath, GhostFSP_ReadWriteable)))
	{
		return GhostErrorFS_MountPointNotExist;
	}

	ghostFS_Inited = true;
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


/// <summary>
/// Initializing file system support for lvgl.
///		This function MUST be called AFTER `lv_init` and `GhostFS_Init`.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostLVGL_FS_Init(void)
{
	if (ghostFS_Inited)
	{
		// Init lvgl file system.
		static lv_fs_drv_t fs_drv;
		lv_fs_drv_init(&fs_drv);

		/*Set up fields...*/
		fs_drv.letter = 'C';
		fs_drv.open_cb = fs_open;
		fs_drv.close_cb = fs_close;
		fs_drv.read_cb = fs_read;
		fs_drv.write_cb = fs_write;
		fs_drv.seek_cb = fs_seek;
		fs_drv.tell_cb = fs_tell;

		fs_drv.dir_close_cb = NULL;// fs_dir_close;
		fs_drv.dir_open_cb = NULL;// fs_dir_open;
		fs_drv.dir_read_cb = NULL;// fs_dir_read;

		lv_fs_drv_register(&fs_drv);
		return GhostOK;
	}
	else {
		return GhostErrorFS_Uninitialized;
	}
}


/// <summary>
/// Get the real path of the file.
/// </summary>
/// <param name="AbsPath">Path from mount directory.</param>
/// <param name="RealPath">Real path, this variable requires manual memory allocation.</param>
/// <param name="RealPathBufferLength">Buffer size of real path.</param>
/// <returns></returns>
GhostError_t GhostFS_GetRealPath(const char* AbsPath, char* RealPath, int RealPathBufferLength)
{
	if (strlen(AbsPath) > MacroMaximumPathLength)
	{
		return GhostErrorFS_PathTooLong;
	}
	else {
#ifdef _WIN32
		if (_fullpath(RealPath, AbsPath, RealPathBufferLength - 1) == NULL)
			return GhostErrorFS_PathTooLong;
#else
#error "TODO in linux."
#error "Welcome pull requests."
#endif
		return GhostOK;
	}
}

/// <summary>
/// Open file.
/// </summary>
/// <param name="FilePath">Similar to the Linux style path starting from the root directory "/".</param>
/// <param name="GhostFile">Pointor to file.</param>
/// <param name="Mode">Mode.</param>
/// <returns>Function execution result.</returns>
/// TODO: Check whether the file exists.
GhostError_t GhostFS_Open(const char* FilePath, GhostFile_t* GhostFile, const char* Mode)
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

	GhostError_t ret = GhostFS_GetRealPath(realPath, realPath, MacroMaximumPathLength + rootDirectoryPathLen);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Check whether the path is legal.
	int minimumPath = 0;
	if (rootDirectoryPathLen < strlen(realPath))
		minimumPath = rootDirectoryPathLen;
	else
		minimumPath = (int)strlen(realPath);

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

	// Unlock mutex.
	ret = GhostMutexUnlock(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Check whether the file was successfully opened.
	if (GhostFile->FileStream == NULL)
		return GhostErrorFS_FileOpenFailed;

	return GhostOK;
}

/// <summary>
/// Flush buffer to file.
/// </summary>
/// <param name="GhostFile"></param>
/// <returns></returns>
GhostError_t GhostFS_Flush(const GhostFile_t* GhostFile)
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
/// <param name="GhostFile">Pointor to file.</param>
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
/// <param name="BufferPtr">Pointor to buffer.</param>
/// <param name="Size">Size of data.</param>
/// <param name="Count">Count of data.</param>
/// <param name="GhostFile">Pointor to file.</param>
/// <returns>ame as fread, equal to the data size actually read.</returns>
int GhostFS_Read(void* BufferPtr, size_t Size, size_t Count, const GhostFile_t* GhostFile)
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
/// <param name="BufferPtr">Pointor to buffer.</param>
/// <param name="Size">Size of data.</param>
/// <param name="Count">Count of data.</param>
/// <param name="GhostFile">Pointor to file.</param>
/// <returns>Same as fwrite, equal to the data size actually written.</returns>
int GhostFS_Write(const void* BufferPtr, size_t Size, size_t Count, const GhostFile_t* GhostFile)
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
/// File offset(seek).
/// </summary>
/// <param name="GhostFile">Pointor to file.</param>
/// <param name="Offset">Offset.</param>
/// <param name="Whence">Offset start position.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostFS_Seek(const GhostFile_t* GhostFile, long int Offset, GhostFS_Whence_t Whence)
{
	// Check file handle.
	if (GhostFile == NULL)
		return GhostErrorFS_FileUninitialized;

	// Lock mutex.
	GhostError_t ret = GhostMutexLock(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// fseek;
	if (fseek(GhostFile->FileStream, Offset, Whence))
		return GhostErrorFS_SeekFailed;

	// Unlock mutex.
	ret = GhostMutexUnlock(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return ret;
}


/// <summary>
/// Returns the current file pointer position(ftell).
/// </summary>
/// <param name="GhostFile">Pointor to file.</param>
/// <returns>Same as ftell, return -1L if failed.</returns>
long int GhostFS_Tell(const GhostFile_t* GhostFile)
{
	// Check file handle.
	if (GhostFile == NULL)
		return -1L;

	// Lock mutex.
	GhostError_t ret = GhostMutexLock(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return -1L;

	long int result = ftell(GhostFile->FileStream);

	// Unlock mutex.
	ret = GhostMutexUnlock(&GhostFile->Mutex);
	if (ret.LayerErrorCode != GhostNoError)
		return -1L;

	return result;
}

/// <summary>
/// Get file size.
/// </summary>
/// <param name="GhostFile">Pointor to file.</param>
/// <returns>File size in size_t.</returns>
size_t GhostFS_GetFileSize(const GhostFile_t* GhostFile)
{
	// Check file handle.
	if (GhostFile == NULL)
		return 0;

	// Lock mutex.
	GhostError_t gret = GhostMutexLock(&GhostFile->Mutex);
	if (gret.LayerErrorCode != GhostNoError)
		return 0;

	// Calculate file size.
	size_t originalOffset = ftell(GhostFile->FileStream);
	fseek(GhostFile->FileStream, 0, SEEK_END);
	size_t size = ftell(GhostFile->FileStream);
	fseek(GhostFile->FileStream, 0, originalOffset);

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
char* GhostFS_Join(const char* ParentPath, const char* Subpath)
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
	
	ret = GhostFS_GetRealPath(temp, result, MacroMaximumPathLength);
	if(ret.LayerErrorCode != GhostNoError)
	{
		free(result);
		return NULL;
	}
	return result;
}


/************************************lvgl port implementation.************************************/
/**
 * Open a file
 * @param drv       pointer to a driver where this function belongs
 * @param path      path to the file beginning with the driver letter (e.g. S:/folder/file.txt)
 * @param mode      read: FS_MODE_RD, write: FS_MODE_WR, both: FS_MODE_RD | FS_MODE_WR
 * @return          a file descriptor or NULL on error
 */
static void* fs_open(lv_fs_drv_t* drv, const char* path, lv_fs_mode_t mode)
{
	GhostFile_t* filePtr = calloc(1, sizeof(GhostFile_t));
	if (!filePtr)
	{
		return NULL;
	}

	if (mode == LV_FS_MODE_WR)
	{
		/*Open a file for write*/
		if (IfGhostError(GhostFS_Open(path, filePtr, "wb")))
		{
			free(filePtr);
			return NULL;
		}
	}
	else if (mode == LV_FS_MODE_RD)
	{
		/*Open a file for read*/
		if (IfGhostError(GhostFS_Open(path, filePtr, "rb")))
		{
			free(filePtr);
			return NULL;
		}
	}
	else if (mode == (LV_FS_MODE_WR | LV_FS_MODE_RD))
	{
		/*Open a file for read and write*/
		if (IfGhostError(GhostFS_Open(path, filePtr, "rb+")))
		{
			free(filePtr);
			return NULL;
		}
	}

	return filePtr;
}


/**
 * Close an opened file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable. (opened with fs_open)
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_close(lv_fs_drv_t* drv, void* file_p)
{
	/*Add your code here*/
	if (IfGhostError(GhostFS_Close(file_p)))
	{
		return LV_FS_RES_HW_ERR;
	}

	return LV_FS_RES_OK;
}


/**
 * Read data from an opened file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable.
 * @param buf       pointer to a memory block where to store the read data
 * @param btr       number of Bytes To Read
 * @param br        the real number of read bytes (Byte Read)
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_read(lv_fs_drv_t* drv, void* file_p, void* buf, uint32_t btr, uint32_t* br)
{
	/*Add your code here*/
	*br = GhostFS_Read(buf, 1, btr, file_p);

	return LV_FS_RES_OK;
}


/**
 * Write into a file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable
 * @param buf       pointer to a buffer with the bytes to write
 * @param btw       Bytes To Write
 * @param bw        the number of real written bytes (Bytes Written). NULL if unused.
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_write(lv_fs_drv_t* drv, void* file_p, const void* buf, uint32_t btw, uint32_t* bw)
{
	/*Add your code here*/
	*bw = GhostFS_Write(buf, 1, btw, file_p);

	return LV_FS_RES_OK;
}


/**
 * Set the read write pointer. Also expand the file size if necessary.
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable. (opened with fs_open )
 * @param pos       the new position of read write pointer
 * @param whence    tells from where to interpret the `pos`. See @lv_fs_whence_t
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_seek(lv_fs_drv_t* drv, void* file_p, uint32_t pos, lv_fs_whence_t whence)
{
	/*Add your code here*/
	if (IfGhostError(GhostFS_Seek(file_p, pos, whence)))
		return LV_FS_RES_HW_ERR;

	return LV_FS_RES_OK;
}


/**
 * Give the position of the read write pointer
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable.
 * @param pos_p     pointer to to store the result
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_tell(lv_fs_drv_t* drv, void* file_p, uint32_t* pos_p)
{
	/*Add your code here*/
	int pos = GhostFS_Tell(file_p);
	if (pos < 0)
	{
		return LV_FS_RES_HW_ERR;
	}
	*pos_p = pos;

	return LV_FS_RES_OK;
}

/**
 * Initialize a 'lv_fs_dir_t' variable for directory reading
 * @param drv       pointer to a driver where this function belongs
 * @param path      path to a directory
 * @return          pointer to the directory read descriptor or NULL on error
 */
static void* fs_dir_open(lv_fs_drv_t* drv, const char* path)
{
	void* dir = NULL;
	/*Add your code here*/
	//dir = ...           /*Add your code here*/
	return dir;
}

/**
 * Read the next filename form a directory.
 * The name of the directories will begin with '/'
 * @param drv       pointer to a driver where this function belongs
 * @param rddir_p   pointer to an initialized 'lv_fs_dir_t' variable
 * @param fn        pointer to a buffer to store the filename
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_dir_read(lv_fs_drv_t* drv, void* rddir_p, char* fn)
{
	lv_fs_res_t res = LV_FS_RES_NOT_IMP;

	/*Add your code here*/

	return res;
}

/**
 * Close the directory reading
 * @param drv       pointer to a driver where this function belongs
 * @param rddir_p   pointer to an initialized 'lv_fs_dir_t' variable
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_dir_close(lv_fs_drv_t* drv, void* rddir_p)
{
	lv_fs_res_t res = LV_FS_RES_NOT_IMP;

	/*Add your code here*/

	return res;
}
