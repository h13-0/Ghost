#include "App.h"

// Standard libraries.
#include <stddef.h>
#include <stdio.h>

// Configs.
#include "GhostPlatformConfigs.h"

// Drivers layer.
/// FileSystem.
#include "GhostFileSystem.h"
#include "GhostThread.h"
#include "GhostClock.h"

// App layer.
/// Components.
#include "GhostLog.h"
#include "GhostApplicationManager.h"
#include "GhostSafeLVGL.h"

/// Applications.
#include "GhostLauncher.h"

// Thirdparty layer.
#include "lvgl.h"
#include "cJSON.h"

// Test libraries.
#include "GhostFileSystemPatch.h"

static GhostError_t ghostAppInit(void)
{
	// Init Ghost log.
	{
		GhostError_t ret = GhostLogInit(MacroMinimumLogLevel);
		if (IfGhostError(ret))
		{
			return ret;
		}
	}

	// Init Ghost safe lvgl.
	GhostLogRetIfErr(Fatal, GhostSafeLV_Init());

	// Init Ghost application manager.
	GhostLogRetIfErr(Fatal, GhostAppMgrInit());

	// Register native applications.
	// Run Ghost System.
	{
		GhostAppInfo_t app = MacroGhostLauncherInfo;
		GhostLogRetIfErr(Fatal, GhostAppMgrRegister(&app));
		// Run Ghost System(But do nothing).
		GhostLogRetIfErr(Fatal, GhostAppMgrRunForeground(app.PackageName, 1, "Ghost system call."));
	}

	GhostLogI("Ghost init successfully.");

	return GhostOK;
}

static GhostError_t ghostAppDeInit(void)
{
	// TODO.
	return GhostOK;
}

void btn_event_cb(lv_event_t* e)
{
	printf("Clicked\n");
}


GhostError_t GhostAppRun(void)
{
	ghostAppInit();
	
	GhostError_t ret = GhostOK;
	GhostAppInfo_t info = MacroGhostLauncherInfo;
	ret = GhostAppMgrGetInfoByPackageName("tech.h13.ghost.launcher", &info);
	cJSON* json;

	while (1)
	{
		GhostSleepMillisecond(1000);
	}

	ghostAppDeInit();

	return GhostOK;
}

GhostError_t GhostTimerHandler(float TimeIntervalInMillisecond)
{
	// Refresh UI.
	return GhostSafeLV_HeartBeat(TimeIntervalInMillisecond);
}

GhostError_t GhostPowerOff(void)
{
	//TODO.
	return GhostOK;
}
