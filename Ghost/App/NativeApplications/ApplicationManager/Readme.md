# How to use application manager.


## Package operations.
### Register a new application.

## Permission manager.

### Function list
- [ ] User grouping.
- [ ] File permission management.


### Initialize Permission manager.
#### Register application.
```C

```

### File manager.
**After opening the file, you can use `GhostFileSystem` for file operation.**
#### Open file.
`GhostAppOpenFile` 

```C
/// <summary>
/// Open the file in the name of app.
///		**After the file is opened, you can use ghostfs to operate the file.**
/// </summary>
/// <param name="Application">Application info.</param>
/// <param name="File"></param>
/// <returns></returns>
GhostError_t GhostAppOpenFile(GhostApplicationInfo_t* Application, GhostFile_t* File, char* Mode);
```
