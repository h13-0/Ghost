#pragma once

#include "GhostPlatformConfigs.h"

#include "GhostErrorDefine.h"
#include "GhostSoftwareErrorDefine.h"

#define GhostErrorLogInitFailed        DeclareGhostError(GhostDriverLayerError, DriverModuleLogError, 1)
#define GhostErrorLogUninitialized     DeclareGhostError(GhostDriverLayerError, DriverModuleLogError, 2)
#define GhostErrorLogOutOfMemory       DeclareGhostError(GhostDriverLayerError, DriverModuleLogError, 3)

#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// Typedef of GhostLogLevel.
	/// </summary>
	typedef enum
	{
		Debug = 0,
		Info = 1,
		Warning = 2,
		Error = 3,
		Fatal = 4
	} GhostLogLevel_t;


	/// <summary>
	/// Initialize Ghost log.
	/// </summary>
	/// <param name="MinimumLogLevel">Lowest log level to be recorded.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostLogInit(GhostLogLevel_t MinimumLogLevel);


	/// <summary>
	/// Typedef of GhostLogFunc_t.
	/// <param name="Level">Log level in GhostLogLevel_t.</param>
	/// <param name="Time">Microseconds since startup.</param>
	/// <param name="FileName">File name with error.</param>
	/// <param name="LineNumber">Line number with errors.</param>
	/// <param name="Contents">Log contents.</param>
	/// </summary>
	typedef void(*GhostLogFunc_t)(GhostLogLevel_t Level, double Time, const char* FileName, int LineNumber, const char* Contents);


	/// <summary>
	/// Register ghost log output function.
	/// </summary>
	/// <param name="Func">Pointor to function.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostLogOutputFuncRegister(GhostLogFunc_t Func);


	/// <summary>
	/// Reset log level.
	/// </summary>
	/// <param name="MinimumLogLevel">Lowest log level to be recorded.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostLogSetMinimumLogLevel(GhostLogLevel_t MinimumLogLevel);


	/// <summary>
	/// **Private** log implementation.
	///		**Please use subsequent public implementations.**
	/// </summary>
	/// <param name="Level">Log level in GhostLogLevel_t.</param>
	/// <param name="FileName">File name with error.</param>
	/// <param name="LineNumber">Line number with errors.</param>
	/// <param name="Format">Formatted error message.</param>
	/// <param name="...">Variable parameters.</param>
	/// <returns>Function execution result.</returns>
#if(MacroGhostLogOutputFileName && MacroGhostLogOutputLineNumber)
	GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, const char* FileName, int LineNumber, char* Format, ...);
#define __ghostLog__(Level, FileName, LineNumber, Format, ...)   __ghostPrivateLogImpl__(Level, FileName, LineNumber, Format, ##__VA_ARGS__) 
#elif(MacroGhostLogOutputFileName)
	GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, const char* FileName, char* Format, ...);
#define __ghostLog__(Level, FileName, LineNumber, Format, ...)   __ghostPrivateLogImpl__(Level, FileName, Format, ##__VA_ARGS__)
#elif(MacroGhostLogOutputLineNumber)
	GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, int LineNumber, char* Format, ...);
#define __ghostLog__(Level, FileName, LineNumber, Format, ...)   __ghostPrivateLogImpl__(Level, LineNumber, Format, ##__VA_ARGS__)
#else
	GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, char* Format, ...);
#define __ghostLog__(Level, FileName, LineNumber, Format, ...)   __ghostPrivateLogImpl__(Level, Format, ##__VA_ARGS__)
#endif


	/// <summary>
	/// **Private** log implementation.
	///		**Please use subsequent public implementations.**
	/// </summary>
	/// <param name="LogLevel">Log level.</param>
	/// <param name="ErrorRet">Return value in GhostError_t.</param>
	/// <param name="FileName">File name with error.</param>
	/// <param name="LineNumber">Line number with errors.</param>
	/// <returns>Return true if error occurred.</returns>
	bool __ghostLogRetIfErrImpl__(GhostLogLevel_t LogLevel, GhostError_t ErrorRet, const char* FileName, int LineNumber);


	/// <summary>
	/// **Private** log implementation.
	///		**Please use subsequent public implementations.**
	/// </summary>
	/// <param name="LogLevel">Log level.</param>
	/// <param name="ErrorRet">Return value in GhostError_t.</param>
	/// <param name="SourceCode">Source code of the function.</param>
	/// <param name="FileName">File name with error.</param>
	/// <param name="LineNumber">Line number with errors.</param>
	void __ghostLogFuncResultImpl__(GhostLogLevel_t LogLevel, GhostError_t ErrorRet, const char* SourceCode, const char* FileName, int LineNumber);


	/// <summary>
	/// Standard GhostLog function.
	/// </summary>
	/// <param name="LogLevel">Log level.</param>
	/// <param name="Format">Formatted error message.</param>
	/// <param name="...">Variable parameters.</param>
	/// <returns>Function execution result.</returns>
#define GhostLog(LogLevel, Format, ...)               __ghostLog__(LogLevel, __FILE__, __LINE__, Format, ##__VA_ARGS__)


	/// <summary>
	/// Abbreviated GhostLog functions.
	/// </summary>
	/// <param name="Format">Formatted error message.</param>
	/// <param name="...">Variable parameters.</param>
	/// <returns>Function execution result.</returns>
#define GhostLogD(Format, ...)              GhostLog(Debug, Format, ##__VA_ARGS__)
#define GhostLogI(Format, ...)              GhostLog(Info, Format, ##__VA_ARGS__)
#define GhostLogW(Format, ...)              GhostLog(Warning, Format, ##__VA_ARGS__)
#define GhostLogE(Format, ...)              GhostLog(Error, Format, ##__VA_ARGS__)
#define GhostLogF(Format, ...)              GhostLog(Fatal, Format, ##__VA_ARGS__)

	
	/// <summary>
	/// Output GhostErrorRet through log, which is usually used for function test.
	///		This function **CANNOT** be understood as a common C language function.
	/// </summary>
	/// <param name="LogLevel">Log level.</param>
	/// <param name="GhostErrorRet">Function with GhostError_t as return value or return value of GhostError_t.</param>
#define GhostLogFuncResult(LogLevel, GhostErrorRet)   do{ \
                                                            __ghostLogFuncResultImpl__(LogLevel, GhostErrorRet, #GhostErrorRet, __FILE__, __LINE__); \
                                                        } while(0);

#define GhostLogIfError(LogLevel, GhostErrorRet)      do{ \
                                                            if(IfGhostError(GhostErrorRet)) \
                                                                __ghostLogFuncResultImpl__(LogLevel, GhostErrorRet, #GhostErrorRet, __FILE__, __LINE__); \
                                                        } while(0);


	/// <summary>
	/// Check whether the Ghost function is successfully executed. If not, **return** the return value of the Ghost function in advance.
	///		This function **CANNOT** be understood as a common C language function.
	///		Please use this function with **CAUTION:**
	///			When GhostErrorRet is not GhostOK, the operation of this function will be **TERMINATED** in advance and GhostErrorRet will be returned.
	/// </summary>
	/// <param name="LogLevel">Log level.</param>
	/// <param name="GhostErrorRet">Function with GhostError_t as return value or return value of GhostError_t.</param>
	/// <returns>Same as GhostErrorRet.</returns>
#define GhostLogTerminateIfErr(LogLevel, GhostErrorRet)        do{ \
                                                                    if(IfGhostError(GhostErrorRet)) { \
                                                                        __ghostLogRetIfErrImpl__(LogLevel, GhostErrorRet, __FILE__, __LINE__); \
                                                                        return GhostErrorRet; \
                                                                    } \
                                                                 } while(0);

#ifdef __cplusplus
}
#endif
