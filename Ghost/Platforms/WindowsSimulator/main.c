#include "QT_Simulator.h"

#include "App.h"

#include "GhostClock.h"

#include <time.h>

#include "pthread.h"

static void* ghostRun(void* args)
{
	GhostSleepMillisecond(3000);
	GhostError_t ret = GhostAppRun();
	if (ret.LayerErrorCode == GhostNoError)
	{

	}
	else {
		
	}
}

static void* ghostTimer(void* args)
{
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
		Sleep(10);
	}

	while (1)
	{
		to.tv_sec = time(NULL);
		to.tv_nsec = 100000;
		if (pthread_cond_timedwait(&cond, &mutex, &to) == ETIMEDOUT)
		{
			GhostTimerHandler((clock() - lastExecuteTime) * 1000.0 / CLOCKS_PER_SEC);
			lastExecuteTime = clock();
		}
	}
}

int main(int argc, char* argv[])
{
	// Init Platform layer.
	GhostQT_Simulator_t simulator;
	GhostQT_SimulatorInit(&simulator, argc, argv);

	// Init Drivers.
	GhostClockInit();
	// Init software.
	// Init lvgl.
	lv_init();
	// Init lvgl display devices.
	lv_port_disp_init(&simulator);

	// Init and run Ghost project.
	pthread_t ghostRunThread;
	pthread_t ghostTimerThread;
	GhostError_t ret = GhostAppInit();
	if (ret.LayerErrorCode == GhostNoError)
	{
		int pret = pthread_create(&ghostRunThread, NULL, ghostRun,NULL);
		if (pret != 0)
		{
			//
		}
		else {

		}

		pret = pthread_create(&ghostTimerThread, NULL, ghostTimer, NULL);
		if (pret != 0)
		{
			//
		}
		else {

		}
	}
	else {
		//Log.
	}

	// Run simulator.
	GhostQT_SimulatorRun(&simulator);

	// Wait for the child thread to end.
	pthread_join(ghostRunThread, NULL);
	pthread_join(ghostTimerThread, NULL);

	return 0;
}
