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

#define GhostLog(LogLevel, Format, ...)               __ghostPrivateLogImpl__(LogLevel, __FILE__, __LINE__, Format, ##__VA_ARGS__)


#define GhostLogRetIfErr(LogLevel, GhostErrorRet)     do{ \
															if(IfGhostError(GhostErrorRet)) { \
																GhostLog(LogLevel, "Error occurred, LayerErrorCode: %d, ModuleErrorCode: %d, SubErrorCode: %d , returned.", GhostErrorRet.LayerErrorCode, GhostErrorRet.ModuleErrorCode, GhostErrorRet.SubErrorCode); \
																return GhostErrorRet; \
															} \
														} while(0)

#ifdef __cplusplus
}
#endif

