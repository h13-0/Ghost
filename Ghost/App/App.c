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

// Ghost app status.
static GhostMutex_t statusMutex;
static GhostStatus_t ghostStatus = GhostUninitialized;

GhostError_t GhostAppInit(void)
{
	GhostMutexInit(&statusMutex);

	// Init Ghost safe lvgl.
	GhostLogTerminateIfErr(Fatal, GhostSafeLV_Init());

	// Init Ghost application manager.
	GhostLogTerminateIfErr(Fatal, GhostAppMgrInit());

	// Register native applications.
	// Run Ghost System.
	{
		GhostAppInfo_t app = MacroGhostLauncherInfo;
		GhostLogTerminateIfErr(Fatal, GhostAppMgrRegister(&app));
		// Run Ghost System(But do nothing).
		GhostLogTerminateIfErr(Fatal, GhostAppMgrRunForeground(app.PackageName, 1, "Ghost system call."));
	}

	GhostLogI("Ghost init successfully.");

	GhostLogTerminateIfErr(Fatal, GhostMutexLock(&statusMutex));
	ghostStatus = GhostRunning;
	GhostLogTerminateIfErr(Fatal, GhostMutexUnlock(&statusMutex));

	return GhostOK;
}

GhostError_t GhostAppDeInit(void)
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
	GhostAppInfo_t info = MacroGhostLauncherInfo;
	GhostLogTerminateIfErr(Fatal, GhostAppMgrGetInfoByPackageName("tech.h13.ghost.launcher", &info));

	while (1)
	{
		GhostSleepMillisecond(1000);
	}

	GhostAppDeInit();

	return GhostOK;
}

GhostStatus_t GhostAppStatus(void)
{
	GhostStatus_t status = GhostUninitialized;
	if (IfGhostError(GhostMutexLock(&statusMutex)))
	{
		return GhostUninitialized;
	}
	status = ghostStatus;
	if (IfGhostError(GhostMutexUnlock(&statusMutex)))
	{
		return GhostUninitialized;
	}
	return status;
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
