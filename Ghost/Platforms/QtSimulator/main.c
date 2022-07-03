#include "GhostPlatformConfigs.h"

#include "QtSimulator.h"

//#include "lv_png.h"

#include "App.h"

#include "GhostThread.h"
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

static void* ghostRun(void* args)
{
	// Wait Qt Simulator inited.
	while (IfGhostError(GhostQtSimulatorInited(&simulator)))
	{
		GhostSleepMillisecond(100);
	}

	// Init Ghost thread(To enable GhostLog).
	if (IfGhostError(GhostThreadInit()))
		exit(1);

	// Init Ghost log.
	if (IfGhostError(GhostLogInit(MacroGhostLogMinimumLogLevel)))
		exit(2);

	// Register log output function.
	if (IfGhostError(GhostLogOutputFuncRegister(logToQtSimulator)))
		exit(3);

	// Regeister log output file.


	// Init Drivers.
	/// Clock.
	if (IfGhostError(GhostClockInit()))
	{
		GhostLogF("Ghost clock init error.");
	}

	/// FileSystem.
	if (IfGhostError(GhostFS_Init(MacroFileSystemMountPoint)))
	{
		GhostLogF("Ghost file system init error, please check if the file system exists.");
	}


	// Init software.
	// Init lvgl.
	lv_init();
	// Init lvgl display devices.
	lv_port_disp_init(&simulator);
	// Init lvgl file system.
	if (IfGhostError(GhostLVGL_FS_Init()))
	{
		GhostLogF("Ghost lvgl file system init error, please check whether the GhostFileSystem is initialized successfully.");
	}

	// Init lvgl lib png support.
	lv_png_init();

	if(IfGhostError(GhostAppInit()))
	{
		exit(5);
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

		pthread_join(ghostTimerThread, NULL);
		GhostAppRun();
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

	// Wait for the child thread to end.
	pthread_join(ghostRunThread, NULL);

	return 0;
}
