#include "GhostLauncher.h"

#include "GhostPlatformConfigs.h"

#include <stdio.h>

#include "GhostSafeLVGL.h"
#include "GhostApplicationManager.h"

// Drivers
#include "GhostClock.h"

static GhostApplicationInfo_t appInfo;

/// <summary>
/// Entry function of Ghost Launcher.
/// </summary>
/// <param name="Argc">Arguments' count.</param>
/// <param name="Args">Pointor of Arguments.</param>
/// <returns></returns>
GhostError_t GhostLauncherRun(int Argc, void** Args)
{
#ifdef _DEBUG
	// TODO: Record and output arguments.
	
#endif
	
	// TODO: Check whether the theme is used.
	// Get application config.
	appInfo = MacroGhostLauncherInfo;
	cJSON* configs = NULL;
	GhostAppMgrGetAppConfigJSON(&appInfo, &configs);


	// TODO: Built in themes.
	// Default theme.

	
	char timeText[16] = { 0 };

	GhostLV_Lock();
	lv_obj_t* timeLabel = lv_label_create(lv_scr_act());
	lv_obj_set_width(timeLabel, 150);
	lv_label_set_text_static(timeLabel, timeText);
	lv_obj_set_style_text_font(timeLabel, &lv_font_montserrat_48, 0);
	lv_obj_align(timeLabel, LV_ALIGN_CENTER, 0, 40);
	GhostLV_Unlock();

	while (1)
	{
		int hour, minute, second;
		GhostGetCurrentTime(&hour, &minute, &second);

		if (second % 2 == 0)
		{
			sprintf(timeText, "%02d:%02d", hour, minute);
		}
		else {
			sprintf(timeText, "%02d %02d", hour, minute);
		}

		LV_Safe(
		lv_label_set_text_static(timeLabel, NULL);
		)

		GhostSleepMillisecond(50);
	}

	return GhostOK;
}
