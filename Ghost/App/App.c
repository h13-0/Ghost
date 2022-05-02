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

static GhostFile_t file = { NULL };

void testThread(void)
{
	char data[] = "Ghooooost!\r\n";
	GhostError_t ret = GhostOK;
	unsigned long long times = 0;
	while (1)
	{
		if (GhostFS_Write(data, sizeof(char), strlen(data), &file) == 0)
			while (1);
		times++;
		printf("GTimes: %d\r\n", times);
		if (times > 1000000)
			while (1);
	}
}

GhostError_t GhostAppRun(void)
{
	char data[] = "Hello, world!\r\n";

	unsigned long long times = 0;

	GhostError_t ret = GhostOK;
	ret = GhostFS_Open("./test.txt", &file, "a+");
	if (ret.LayerErrorCode != GhostNoError)
		while (1);

	GhostThread_t t;
	GhostThreadCreate(&t, testThread, NULL, 0, NULL, 1);

	while (1)
	{
		
		if(GhostFS_Write(data, sizeof(char), strlen(data), &file) == 0)
			while (1);
		times++;
		printf("HTimes: %d\r\n", times);
		if (times > 1000000)
			while (1);
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
