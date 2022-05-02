#include "App.h"

#include <stddef.h>

// Configs.
#include "GhostPlatformConfigs.h"

// Drivers layer.
/// FileSystem.
#include "GhostFileSystem.h"

// App layer.
/// Components.
#include "GhostApplicationManager.h"

/// Applications.
#include "GhostLauncher.h"

#include "GhostClock.h"

// Thirdparty layer.
#include "lvgl.h"

#include <stdio.h>

GhostError_t GhostAppInit(void)
{
	GhostError_t ret = GhostOK;
	
	// Init ghost application manager.
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
	GhostFile_t file;

	char data[] = "Hello, world!";

	GhostError_t ret = GhostOK;
	ret = GhostFS_Open("./test.txt", &file, "w+");
	GhostFS_Write(data, sizeof(char), strlen(data), &file);
	GhostFS_Close(&file);

	while (1)
	{
		GhostSleepMillisecond(100000);
	}

	return GhostOK;
}

GhostError_t GhostTimerHandler(float TimeIntervalInMillisecond)
{
	// Refresh UI.
	lv_tick_inc(TimeIntervalInMillisecond);
	lv_timer_handler();
	return GhostOK;
}
