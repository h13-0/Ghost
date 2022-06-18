#include "GhostLog.h"

#include "GhostPlatformConfigs.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

#include "GhostClock.h"
#include "GhostThread.h"

// Cache current log level.
#ifdef _DEBUG
static GhostLogLevel_t minimumLogLevel = Debug;
#else
static GhostLogLevel_t minimumLogLevel = Info;
#endif

// Output stream pointer list.
static FILE** outputListPtr;
static int outputLogNum = 0;
static bool ghostLogInited = false;
static GhostMutex_t logMutex;

/// <summary>
/// Initialize Ghost log.
/// </summary>
/// <param name="MinimumLogLevel">Lowest log level to be recorded.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostLogInit(GhostLogLevel_t MinimumLogLevel)
{
	minimumLogLevel = MinimumLogLevel;

	// Init log mutex.
	GhostMutexInit(&logMutex);

	// Initialize custom output streams.
	MacroGhostLogOutputInit(outputListPtr, outputLogNum);

	ghostLogInited = true;

	return GhostOK;
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
GhostError_t __ghostPrivateLogImpl__(GhostLogLevel_t Level, const char* FileName, int LineNumber, char* Format, ...)
{
	if (!ghostLogInited)
	{
		return GhostErrorLogUninitialized;
	}
	else
	{
		// Try lock?
		GhostMutexLock(&logMutex);

		if (outputLogNum > 0)
		{
			// Check log level.
			if (Level >= minimumLogLevel)
			{
				// Output to all targets.
				FILE* currentFilePtr = NULL;
				for (int i = 0; i < outputLogNum; i++)
				{
					currentFilePtr = *outputListPtr;
				}
				if (currentFilePtr)
				{
					// Get current time.
					int milliseconds = 0;
					GhostGetCurrentMilliseconds(&milliseconds);

					// Print log level.
					switch (Level) {
					case Debug:
						fprintf(currentFilePtr, "[Debug]: ");
						break;

					case Info:
						fprintf(currentFilePtr, "[Info]: ");
						break;

					case Warning:
						fprintf(currentFilePtr, "[Warning]: ");
						break;

					case Error:
						fprintf(currentFilePtr, "[Error]: ");
						break;

					case Fatal:
						fprintf(currentFilePtr, "[Fatal]: ");
						break;

					default:
						break;
					}

#if(MacroGhostLogOutputFileName && MacroGhostLogOutputLineNumber)
					fprintf(currentFilePtr, "%ldms : %s, %d: ", milliseconds, FileName, LineNumber);
#elif(MacroGhostLogOutputFileName)
					fprintf(currentFilePtr, "%ldms : %s: ", milliseconds, FileName);
#elif(MacroGhostLogOutputLineNumber)
					fprintf(currentFilePtr, "%ldms : %d: ", milliseconds, LineNumber);
#else
					fprintf(currentFilePtr, "%ldms : ", milliseconds);
#endif

					va_list arg;
					va_start(arg, Format);
					vfprintf(currentFilePtr, Format, arg);
					fprintf(currentFilePtr, "\r\n");
					va_end(arg);
					//fprintf(currentFilePtr, Format, ##);
				}
			}
		}

		GhostMutexUnlock(&logMutex);

		return GhostOK;
	}
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
bool __ghostLogRetIfErrImpl__(GhostLogLevel_t LogLevel, GhostError_t ErrorRet, const char* FileName, int LineNumber)
{
	if (IfGhostError(ErrorRet))
	{
		__ghostPrivateLogImpl__(LogLevel, FileName, LineNumber, "Error occurred, LayerCode: %d, ModuleCode: %d, SubCode: %d , returned.", 
			ErrorRet.LayerErrorCode, ErrorRet.ModuleErrorCode, ErrorRet.SubErrorCode);
		return true;
	}
	else {
		return false;
	}
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

