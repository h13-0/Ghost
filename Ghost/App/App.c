#include "App.h"

// Configs.
#include "GhostPlatformConfigs.h"

// Components.
#include "GhostApplicationManager.h"

// Applications.
#include "GhostLauncher.h"

// Thirdparty.
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


	while (1);
	return GhostOK;
}

GhostError_t GhostTimerHandler(float TimeIntervalInMillisecond)
{
	// Refresh UI.
	lv_tick_inc(TimeIntervalInMillisecond);
	lv_timer_handler();
	return GhostOK;
}
