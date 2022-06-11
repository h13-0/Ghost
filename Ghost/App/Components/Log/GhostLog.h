#pragma once

#include "GhostPlatformConfigs.h"

#include "GhostErrorDefine.h"
#include "GhostSoftwareErrorDefine.h"

#define GhostErrorLogInitFailed        DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleLogError, 1)
#define GhostErrorLogUninitialized     DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleLogError, 2)

#ifdef __cplusplus
extern "C" {
#endif
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
	GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, const char* FileName, int LineNumber, char* Format, ...);

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
	/// Standard GhostLog function.
	/// </summary>
	/// <param name="LogLevel">Log level.</param>
	/// <param name="Format">Formatted error message.</param>
	/// <param name="...">Variable parameters.</param>
	/// <returns>Function execution result.</returns>
#define GhostLog(LogLevel, Format, ...)               __ghostPrivateLogImpl__(LogLevel, __FILE__, __LINE__, Format, ##__VA_ARGS__)

	/// <summary>
	/// Abbreviated GhostLog functions.
	/// </summary>
	/// <param name="Format">Formatted error message.</param>
	/// <param name="...">Variable parameters.</param>
	/// <returns>Function execution result.</returns>
#define GhostLogD(Format, ...)              GhostLog(Debug, Format, ##__VA_ARGS__)
#define GhostLogI(Format, ...)              GhostLog(Info, Format, ##__VA_ARGS__)
#define GhostLogW(Format, ...)              GhostLog(Warrning, Format, ##__VA_ARGS__)
#define GhostLogE(Format, ...)              GhostLog(Error, Format, ##__VA_ARGS__)
#define GhostLogF(Format, ...)              GhostLog(Fatal, Format, ##__VA_ARGS__)

	/// <summary>
	/// Check whether the Ghost function is successfully executed. If not, **return** the return value of the Ghost function in advance.
	///		This function **CANNOT** be understood as a common C language function.
	/// </summary>
	/// <param name="Format">Formatted error message.</param>
	/// <param name="...">Variable parameters.</param>
	/// <returns>If GhostErrorRet is GhostOK, the function returns GhostOK.</returns>
#define GhostLogRetIfErr(LogLevel, GhostErrorRet)     do{ \
															if(__ghostLogRetIfErrImpl__(LogLevel, GhostErrorRet, __FILE__, __LINE__)) { \
																return GhostErrorRet; \
															} \
														} while(0); GhostOK

#ifdef __cplusplus
}
#endif

