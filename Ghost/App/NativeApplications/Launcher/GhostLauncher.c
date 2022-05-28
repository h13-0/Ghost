#include "GhostLauncher.h"

#include "GhostPlatformConfigs.h"

#include <stdio.h>

#include "GhostSafeLVGL.h"

// Drivers
#include "GhostClock.h"

GhostError_t GhostLauncherRun(int Argc, void** Args)
{
	// TODO: Check whether the theme is used.

	// TODO: Built in themes.
	// Default theme.

	
	char timeText[16] = { 0 };

	LV_Safe(
	lv_obj_t* timeLabel = lv_label_create(lv_scr_act());
	lv_obj_set_width(timeLabel, 150);
	lv_label_set_text_static(timeLabel, timeText);
	lv_obj_set_style_text_font(timeLabel, &lv_font_montserrat_48, 0);
	lv_obj_align(timeLabel, LV_ALIGN_CENTER, 0, 40);
	)

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
