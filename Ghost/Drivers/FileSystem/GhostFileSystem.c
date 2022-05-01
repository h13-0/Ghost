#include "GhostFileSystem.h"

#include "GhostPlatformConfigs.h"

#include <stdlib.h>
#include <string.h>

static char* rootDirectoryPath = NULL;
static int rootDirectoryPathLen = 0;
static char* realPathBuffer = NULL;

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

	realPathBuffer = malloc(MacroMaximumPathLength + rootDirectoryPathLen);
	if(realPathBuffer == NULL)
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

static GhostError_t getRealFilePath(char* FilePath)
{

	if (strlen(FilePath) > MacroMaximumPathLength)
	{
		return GhostErrorFS_PathTooLong;
	}
	else {
#ifdef _WIN32
		_fullpath(realPathBuffer, FilePath, MacroMaximumPathLength);
#else

#endif
		return GhostOK;
	}
}

/// <summary>
/// Open file.
/// </summary>
/// <param name="FilePath">Similar to the Linux style path starting from the root directory "/".</param>
/// <param name="FilePtr">Pointor of file.</param>
/// <param name="Mode">Mode.</param>
/// <returns></returns>
GhostError_t GhostFS_Open(char* FilePath, FILE* FilePtr, char* Mode)
{
	FilePtr = fopen(FilePath, Mode);
	return GhostOK;
}


