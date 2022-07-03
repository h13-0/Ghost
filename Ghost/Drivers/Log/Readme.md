# Ghost Log library.
This component will init in `GhostAppRun()` and **CANNOT** be used until then.  
That is, this component **CAN ONLY** be used in the GhostApp layer, but **NOT** in the GhostDriver and GhostPlatform.  
In the GhostDriver and GhostPlatform, you only need to return the error information with the `GhostError_t` type as the return value.  

## Native development.
Include Ghost system and Ghost native application.  

## Third party development.
### lua

## Custom log output
Edit `MacroLogOutputInit` in file `GhostPlatformConfigs.h`.  
```C  
///> Ghost log configs.
#define MacroLogOutputInit(OutputStreamListPtr, OutputNum)    do{ \
                                                                    OutputStreamListPtr = calloc(sizeof(FILE*), 1); \
                                                                    *OutputStreamListPtr = stdout; \
                                                                    OutputNum = 1; \
                                                                    if(0) { return GhostErrorLogInitFailed; } \
                                                                }while(0)
```  
1. Modify the buffer size of `OutputStreamListPtr`.  
2. Add new `File_t*` to `OutputStreamListPtr`.  

