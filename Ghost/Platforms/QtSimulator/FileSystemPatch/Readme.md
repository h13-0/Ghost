# Ghost File System Patch.
Since the implementation of non-C standard file APIs such as Linux, windows and FatFs(NonOS) is inconsistent, this patch is required to expand the platform related file APIs.

## Functions to be implemented
### GhostFSP_GetRealPath
This function is used to convert an absolute path to a real path.
```C
/// <summary>
/// Get the real path of the file.
/// </summary>
/// <param name="AbsPath">Path from mount directory.</param>
/// <param name="RealPath">Real path, this variable requires manual memory allocation.</param>
/// <param name="RealPathBufferLength">Buffer size of real path.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostFSP_GetRealPath(const char* AbsPath, char* RealPath, size_t RealPathBufferLength);
```


