#include "GhostFileSystemPatch.h"

#include "GhostPlatformConfigs.h"


/// <summary>
/// Get the real path of the file.
/// </summary>
/// <param name="AbsPath">Path from mount directory.</param>
/// <param name="RealPath">Real path, this variable requires manual memory allocation.</param>
/// <param name="RealPathBufferLength">Buffer size of real path.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostFSP_GetRealPath(const char* AbsPath, char* RealPath, size_t RealPathBufferLength)
{
#if defined(_WIN32)
	// Windows
	if (_fullpath(RealPath, AbsPath, RealPathBufferLength - 1) == NULL)
		return GhostErrorFS_PathPathTooLong;
#elif defined(__linux__)
	// Linux
#error "TODO in linux."
#error "Welcome pull requests."
#else
	// FatFs
#error "TODO in FatFs."
#error "Welcome pull requests."
#endif

	return GhostOK;
}


/// <summary>
/// Check whether the file exists.
///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
/// </summary>
/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
/// <returns>GhostOK is returned when the file exists.</returns>
GhostError_t GhostFSP_IsFileExist(const char* RealPath)
{
#if defined(_WIN32)
	// Windows



#elif defined(__linux__)
	// Linux
#error "TODO in linux."
#error "Welcome pull requests."
#else
	// FatFs
#error "TODO in FatFs."
#error "Welcome pull requests."
#endif

	return GhostOK;
}


/// <summary>
/// Check whether the folder exists.
///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
/// </summary>
/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
/// <returns></returns>
GhostError_t GhostFSP_IsFolderExist(const char* RealPath)
{
#if defined(_WIN32)
	// Windows



#elif defined(__linux__)
	// Linux
#error "TODO in linux."
#error "Welcome pull requests."
#else
	// FatFs
#error "TODO in FatFs."
#error "Welcome pull requests."
#endif

	return GhostOK;
}


/// <summary>
/// Check if the path is a file.
///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
/// </summary>
/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
/// <returns></returns>
GhostError_t GhostFSP_IsFile(const char* RealPath)
{
#if defined(_WIN32)
	// Windows



#elif defined(__linux__)
	// Linux
#error "TODO in linux."
#error "Welcome pull requests."
#else
	// FatFs
#error "TODO in FatFs."
#error "Welcome pull requests."
#endif

	return GhostOK;
}


/// <summary>
/// Check if the path is a folder.
///		**The implementation of this function is inconsistent on windows, Linux and FatFs.**
/// </summary>
/// <param name="RealPath">The real path that ghost can read directly is the system path in windows/linux system or FatFs.</param>
/// <returns></returns>
GhostError_t GhostFSP_IsFolder(const char* RealPath)
{
#if defined(_WIN32)
	// Windows



#elif defined(__linux__)
	// Linux
#error "TODO in linux."
#error "Welcome pull requests."
#else
	// FatFs
#error "TODO in FatFs."
#error "Welcome pull requests."
#endif

	return GhostOK;
}
