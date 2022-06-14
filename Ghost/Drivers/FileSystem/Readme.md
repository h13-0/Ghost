# Ghost File System.
Using C standard file API and platform related file system API to expand API time.
## Ghost system development
### Init GhostFileSystem
```C
/// <summary>
/// Init Ghost file system.
/// </summary>
/// <param name="RootDirectoryPath">Path of root directory.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostFS_Init(const char* RootDirectoryPath);
```

### Open file



### Access file

### Check is file exist

## Native application development
### Open file
Refer to [ApplicationManager](../../App/NativeApplications/ApplicationManager/Readme.md)

### Access file
Refer to [ApplicationManager](../../App/NativeApplications/ApplicationManager/Readme.md)

### Check is file exist
Refer to [ApplicationManager](../../App/NativeApplications/ApplicationManager/Readme.md)


### Read, write, flush, close, get file size, join, 
Same as Ghost system development.

## Third party app development


## Platform path development
Refer to [GhostFileSystemPath](../../Platforms/WindowsSimulator/FileSystemPatch/Readme.md)
