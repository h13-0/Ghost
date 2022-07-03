#include "GhostLog.h"

#include "GhostPlatformConfigs.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#include "lv_conf.h"
#include "lvgl.h"

#include "GhostLog.h"
#include "GhostClock.h"
#include "GhostThread.h"

// Cache current log level.
#ifdef _DEBUG
static GhostLogLevel_t minimumLogLevel = Debug;
#else
static GhostLogLevel_t minimumLogLevel = Info;
#endif

// Set sprintf_s and vsprintf_s impl.
#if _WIN32
// Noting to do.
#else
#warning "Not tested."
#define vsprintf_s snprintf
#endif


// GhostLog mutex.
static GhostMutex_t logMutex;

// GhostLog output function list.
static GhostLogFunc_t* outputFuncList;
static int outputFuncNum = 0;

// Output stream pointer list.
static FILE** outputFileList;
static int outputFileNum = 0;

#if LV_USE_LOG
/// <summary>
/// Register lvgl log output function.
/// </summary>
/// <returns>Function execution result.</returns>
static GhostError_t ghost_lv_log_register();
#endif //LV_USE_LOG


/// <summary>
/// Output log to file.
/// </summary>
/// <param name="Level">Log level in GhostLogLevel_t.</param>
/// <param name="Time">Microseconds since startup.</param>
/// <param name="FileName">File name with error.</param>
/// <param name="LineNumber">Line number with errors.</param>
/// <param name="Contents">Log contents.</param>
static void ghostLogToFile(GhostLogLevel_t Level, double Time, const char* FileName, int LineNumber, const char* Contents)
{
	// Try lock?
	// Do not GhostMutexLock(&logMutex);

}


/// <summary>
/// Initialize Ghost log.
/// </summary>
/// <param name="MinimumLogLevel">Lowest log level to be recorded.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostLogInit(GhostLogLevel_t MinimumLogLevel)
{
	minimumLogLevel = MinimumLogLevel;

	// Init log mutex.
	GhostTerminateIfErr(GhostMutexInit(&logMutex));


#if LV_USE_LOG
	ghost_lv_log_register();
#endif //LV_USE_LOG

	// Add log to file function.
	GhostTerminateIfErr(GhostLogOutputFuncRegister(ghostLogToFile));

	return GhostOK;
}


/// <summary>
/// Register ghost log output function.
/// </summary>
/// <param name="Func">Pointor to function.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostLogOutputFuncRegister(GhostLogFunc_t Func)
{
	// Try lock?
	GhostMutexLock(&logMutex);

	GhostLogFunc_t* newList = calloc(outputFuncNum + 1, sizeof(GhostLogFunc_t));

	if (newList != NULL)
	{
		memcpy_s(newList, (outputFuncNum + 1) * sizeof(GhostLogFunc_t), outputFuncList, outputFuncNum * sizeof(GhostLogFunc_t));
		free(outputFuncList);
		outputFuncList = newList;
		*(outputFuncList + outputFuncNum) = Func;
		outputFuncNum++;
	}

	GhostMutexUnlock(&logMutex);
	if (newList != NULL)
	{
		return GhostOK;
	}
	else {
		return GhostErrorLogOutOfMemory;
	}
}


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
GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, const char* FileName, int LineNumber, char* Format, ...)
#elif(MacroGhostLogOutputFileName)
GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, const char* FileName, char* Format, ...)
#elif(MacroGhostLogOutputLineNumber)
GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, int LineNumber, char* Format, ...)
#else
GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, char* Format, ...)
#endif
{
	// Try lock?
	GhostMutexLock(&logMutex);

	if (outputFuncNum > 0)
	{
		// Check log level.
		if (Level >= minimumLogLevel)
		{
			// Create content buffer.
			static char contents[MacroGhostLogMaximumContentsSize] = { 0 };

			// Get current time.
			double microseconds = 0;
			GhostGetCurrentMicroseconds(&microseconds);

			// Style debug content.
			va_list arg;
			va_start(arg, Format);
			vsprintf_s(contents, MacroGhostLogMaximumContentsSize, Format, arg);
			va_end(arg);

			// Output to all targets.
			GhostLogFunc_t log;
			for (int i = 0; i < outputFuncNum; i++)
			{
				log = *(outputFuncList + i);

				// Output to log func.
#if(MacroGhostLogOutputFileName && MacroGhostLogOutputLineNumber)
				log(Level, microseconds, FileName, LineNumber, contents);
#elif(MacroGhostLogOutputFileName)
				log(Level, microseconds, FileName, -1, contents);
#elif(MacroGhostLogOutputLineNumber)
				log(Level, microseconds, "", LineNumber, contents);
#else
				log(Level, microseconds, "", -1, contents);
#endif
			}

			memset(contents, 0, sizeof(char) * MacroGhostLogMaximumContentsSize);
		}
	}

	GhostMutexUnlock(&logMutex);

	return GhostOK;
}


/// <summary>
/// **Private** log implementation.
///		**Please use subsequent public implementations.**
/// </summary>
/// <param name="LogLevel">Log level.</param>
/// <param name="ErrorRet">Return value in GhostError_t.</param>
/// <param name="FileName">File name with error.</param>
/// <param name="LineNumber">Line number with errors.</param>
/// <returns>Return true if error occurred.</returns>
void __ghostLogRetIfErrImpl__(GhostLogLevel_t LogLevel, GhostError_t ErrorRet, const char* FileName, int LineNumber)
{
	__ghostPrivateLogImpl__(LogLevel, FileName, LineNumber, "Error occurred, LayerCode: %d, ModuleCode: %d, SubCode: %d , returned.", 
		ErrorRet.LayerErrorCode, ErrorRet.ModuleErrorCode, ErrorRet.SubErrorCode);
}


/// <summary>
/// **Private** log implementation.
///		**Please use subsequent public implementations.**
/// </summary>
/// <param name="LogLevel">Log level.</param>
/// <param name="ErrorRet">Return value in GhostError_t.</param>
/// <param name="SourceCode">Source code of the function.</param>
/// <param name="FileName">File name with error.</param>
/// <param name="LineNumber">Line number with errors.</param>
void __ghostLogFuncResultImpl__(GhostLogLevel_t LogLevel, GhostError_t ErrorRet, const char* SourceCode, const char* FileName, int LineNumber)
{
	if (IfGhostError(ErrorRet))
	{
		__ghostPrivateLogImpl__(LogLevel, FileName, LineNumber, "Error in function `%s`, LayerCode: %d, ModuleCode: %d, SubCode: %d.",
			SourceCode, ErrorRet.LayerErrorCode, ErrorRet.ModuleErrorCode, ErrorRet.SubErrorCode);
	}
	else {
		__ghostPrivateLogImpl__(LogLevel, FileName, LineNumber, "Function `%s` executed successfully.",
			SourceCode, ErrorRet.LayerErrorCode, ErrorRet.ModuleErrorCode, ErrorRet.SubErrorCode);
	}
}


/// <summary>
/// Reset log level.
/// </summary>
/// <param name="MinimumLogLevel">Lowest log level to be recorded.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostLogSetMinimumLogLevel(GhostLogLevel_t MinimumLogLevel)
{
	// Try lock?
	GhostMutexLock(&logMutex);
	minimumLogLevel = MinimumLogLevel;
	GhostMutexUnlock(&logMutex);

	return GhostOK;
}


/// <summary>
/// 
/// </summary>
/// <param name="level"></param>
/// <param name="file"></param>
/// <param name="line"></param>
/// <param name="fn_name"></param>
/// <param name="dsc"></param>
static void ghost_lv_log_impl(const char* dsc)
{
	__ghostPrivateLogImpl__(Debug, "[lvgl]", 0, "GhostLVGL: %s", dsc);
}


/// <summary>
/// Register lvgl log output function.
/// </summary>
/// <returns>Function execution result.</returns>
static GhostError_t ghost_lv_log_register()
{
	lv_log_register_print_cb(ghost_lv_log_impl);
	return GhostOK;
}
