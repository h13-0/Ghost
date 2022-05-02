#include "App.h"

#include <stddef.h>

// Configs.
#include "GhostPlatformConfigs.h"

// Drivers layer.
/// FileSystem.
#include "GhostFileSystem.h"
#include "GhostThread.h"

// App layer.
/// Components.
#include "GhostApplicationManager.h"
#include "GhostSafeLVGL.h"

/// Applications.
#include "GhostLauncher.h"

#include "GhostClock.h"

// Thirdparty layer.
#include "lvgl.h"

#include <stdio.h>

GhostError_t GhostAppInit(void)
{
	GhostError_t ret = GhostOK;
	
	// Init Ghost safe lvgl.
	GhostSafeLV_Init();

	// Init Ghost application manager.
	ret = GhostAppMgrInit();
	if (ret.LayerErrorCode != GhostNoError)
		return ret;

	// Register native applications.
	GhostApplicationInfo_t app = MacroGhostLauncherInfo;
	GhostAppMgrRegister(&app);
	GhostAppMgrRunForeground(app.PackageName, 1, "Ghost system call.");

	return GhostOK;
}

void btn_event_cb(lv_event_t* e)
{
	printf("Clicked\n");
}


GhostError_t GhostAppRun(void)
{
	while (1)
	{
		GhostSleepMillisecond(1000);
	}

	return GhostOK;
}

GhostError_t GhostTimerHandler(float TimeIntervalInMillisecond)
{
	// Refresh UI.
	return GhostSafeLV_HeartBeat(TimeIntervalInMillisecond);
}
