#include "GhostPlatformConfigs.h"

#include "QtSimulator.h"

//#include "lv_png.h"

#include "App.h"

#include "GhostThread.h"
#include "GhostMemoryManager.h"
#include "GhostLog.h"
#include "GhostClock.h"
#include "GhostFileSystem.h"

#include <stdlib.h>

#include "pthread.h"

static GhostQtSimulator_t simulator;


/// <summary>
/// Output log to Qt simulator ui.
/// </summary>
/// <param name="Level">Log level in GhostLogLevel_t.</param>
/// <param name="Time">Microseconds since startup.</param>
/// <param name="FileName">File name with error.</param>
/// <param name="LineNumber">Line number with errors.</param>
/// <param name="Contents">Log contents.</param>
static void logToQtSimulator(GhostLogLevel_t Level, double Time, const char* FileName, int LineNumber, const char* Contents)
{
	switch (Level)
	{
	case Debug:
		GhostQtSimulatorLog(&simulator, QtSimDebug, Time, FileName, LineNumber, Contents);
		break;

	case Info:
		GhostQtSimulatorLog(&simulator, QtSimInfo, Time, FileName, LineNumber, Contents);
		break;

	case Warning:
		GhostQtSimulatorLog(&simulator, QtSimWarning, Time, FileName, LineNumber, Contents);
		break;

	case Error:
		GhostQtSimulatorLog(&simulator, QtSimError, Time, FileName, LineNumber, Contents);
		break;

	case Fatal:
		GhostQtSimulatorLog(&simulator, QtSimFatal, Time, FileName, LineNumber, Contents);
		break;

	default:
		break;
	}
}

static void* ghostTimer(void* args)
{
	// Wait Qt Simulator inited.
	while (IfGhostError(GhostQtSimulatorInited(&simulator)))
	{
		GhostSleepMillisecond(100);
	}

	static clock_t lastExecuteTime = 0;

	pthread_cond_t cond;
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	struct timespec to;

	pthread_mutex_lock(&mutex);


	while (1)
	{
		GhostTimerHandler(10);
		GhostSleepMillisecond(10);
	}
}

static void* ghostQtPerformanceMonitorRun(void* args)
{
	char memUsageLabelTextBuffer[64] = { "\0" };
	char peakMemUsageLabelTextBuffer[64] = { "\0" };

	while (1)
	{
		size_t usage = GhostMemMgrGetMemUsage();
		GhostQtSimulatorSetMemoryUsageProgressBarValue(&simulator, usage * 100 / MacroMaximumMemoryUsageLimit);
		
		sprintf(memUsageLabelTextBuffer, "%ld Bytes / %ld Bytes", usage, MacroMaximumMemoryUsageLimit);
		GhostQtSimulatorSetMemoryUsageLabelText(&simulator, memUsageLabelTextBuffer);

		usage = GhostMemMgrGetPeakMemUsage();
		sprintf(peakMemUsageLabelTextBuffer, "%ld Bytes", usage);
		GhostQtSimulatorSetPeakMemoryUsageLabelText(&simulator, peakMemUsageLabelTextBuffer);

		GhostSleepMillisecond(500);
	}
}


static void* ghostRun(void* args)
{
	// Wait Qt Simulator inited.
	while (IfGhostError(GhostQtSimulatorInited(&simulator)))
	{
		GhostSleepMillisecond(100);
	}

	// Init Drivers.
	/// GhostThread.
	if (IfGhostError(GhostThreadModuleInit()))
	{
		logToQtSimulator(Fatal, 0, __FILE__, __LINE__, "Ghost thread init failed.");
		return NULL;
	}
	
	/// GhostMemMgr.
	if (IfGhostError(GhostMemMgrInit(MacroMaximumMemoryUsageLimit)))
	{
		logToQtSimulator(Fatal, 0, __FILE__, __LINE__, "Ghost memory manager init failed.");
		return NULL;
	}

	/// GhostClock.
	if (IfGhostError(GhostClockInit()))
	{
		logToQtSimulator(Fatal, 0, __FILE__, __LINE__, "Ghost clock init failed.");
		return NULL;
	}

	/// GhostLog
	if (IfGhostError(GhostLogInit(MacroGhostLogMinimumLogLevel)))
	{
		logToQtSimulator(Fatal, 0, __FILE__, __LINE__, "Ghost log init failed.");
		return NULL;
	}

	// Enable GhostMemoryManager log output.
	GhostMemMgrSetLogEnableStatus(true);

	// Register log output function.
	if (IfGhostError(GhostLogOutputFuncRegister(logToQtSimulator)))
	{
		logToQtSimulator(Fatal, 0, __FILE__, __LINE__, "Ghost log function register failed.");
		return NULL;
	}

	// Regeister log output file.

	/// FileSystem.
	if (IfGhostError(GhostFS_Init(MacroFileSystemMountPoint)))
	{

		GhostLogF("Ghost file system init error, please check if the file system exists.");
		return NULL;
	}


	// Init software.
	// Init lvgl.
	lv_init();
	// Init lvgl display devices.
	lv_port_disp_init(&simulator);
	lv_port_touchpad_init(&simulator);
	// Init lvgl file system.
	if (IfGhostError(GhostLVGL_FS_Init()))
	{
		GhostLogF("Ghost lvgl file system init error, please check whether the GhostFileSystem is initialized successfully.");
		return NULL;
	}

	// Init Ghost app.
	if(IfGhostError(GhostAppInit()))
	{
		GhostLogF("Ghost app init failed.");
		return NULL;
	}
	else {
		pthread_t ghostTimerThread;
		// Run Ghost timer.
		int pret = pthread_create(&ghostTimerThread, NULL, ghostTimer, NULL);
		if (pret != 0)
		{
			//
		}
		else {

		}

		pthread_t ghostPerformancMonitorThread;
		// Run performance monitor.
		pret = pthread_create(&ghostPerformancMonitorThread, NULL, ghostQtPerformanceMonitorRun, NULL);
		if (pret != 0)
		{
			//
		}
		else {

		}

		GhostAppRun();

		pthread_join(ghostTimerThread, NULL);
		return NULL;
	}
}


int main(int argc, char* argv[])
{
	// Init Platform layer.
	if (IfGhostError(GhostQtSimulatorInit(&simulator, argc, argv)))
		return 1;

	// Init and run Ghost project.
	pthread_t ghostRunThread;

	// Run Ghost.
	int pret = pthread_create(&ghostRunThread, NULL, ghostRun, NULL);
	if (pret != 0)
	{
		//
	}
	else {

	}

	// Run simulator.
	GhostQtSimulatorRun(&simulator);

	exit(0);

	// Wait for the child thread to end.
	pthread_join(ghostRunThread, NULL);

	return 0;
}
