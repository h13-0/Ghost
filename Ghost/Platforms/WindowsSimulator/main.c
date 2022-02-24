#include "QT_Simulator.h"

#include "App.h"

#include "pthread.h"

static void* ghostRun(void* args)
{
	GhostError_t ret = GhostAppRun();
	if (ret.LayerErrorCode == GhostNoError)
	{

	}
	else {
		
	}
}

int main(int argc, char* argv[])
{
	// Init Platform layer.
	GhostQT_Simulator_t simulator;
	GhostQT_SimulatorInit(&simulator, argc, argv);

	// Init and run Ghost project.
	GhostError_t ret = GhostAppInit();
	pthread_t ghostThread;
	if (ret.LayerErrorCode == GhostNoError)
	{
		
		int pret = pthread_create(&ghostThread, NULL, ghostRun,NULL);
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

	// Run simulator ui.
	GhostQT_SimulatorRun(&simulator);

	// Wait for the child thread to end.
	pthread_join(ghostThread, NULL);

	return 0;
}
