#include "GhostLauncher.h"

#include "GhostPlatformConfigs.h"

#include <stdio.h>

#include "GhostLog.h"
#include "GhostSafeLVGL.h"
#include "GhostApplicationManager.h"

// Drivers
#include "GhostClock.h"

#include "safe_lvgl.h"

DeclareNativeAppInfo();


static lv_obj_t* mainPage;


/// <summary>
/// 
/// </summary>
/// <returns></returns>
static GhostError_t themeInit();


/// <summary>
/// 
/// </summary>
/// <param name="mainPage"></param>
/// <returns></returns>
static GhostError_t mainPageCreate(lv_obj_t* mainPage);


/// <summary>
/// 
/// </summary>
/// <param name="mainPage"></param>
/// <returns></returns>
static GhostError_t mainPageRefresh(lv_obj_t* mainPage);


/// <summary>
/// 
/// </summary>
/// <param name="standbyPage"></param>
/// <returns></returns>
static GhostError_t standbyPageCreate(lv_obj_t* standbyPage);


/// <summary>
/// 
/// </summary>
/// <param name="standbyPage"></param>
/// <returns></returns>
static GhostError_t standbyPageRefresh(lv_obj_t* standbyPage);


/// <summary>
/// Entry function of Ghost Launcher.
/// </summary>
/// <param name="Args">Pointor of Arguments.</param>
/// <returns></returns>
GhostError_t GhostLauncherRun(void* Args)
{
	GhostAppNativeInfoInit(MacroGhostLauncherPackageName);

#ifdef _DEBUG
	// TODO: Record and output arguments.
	
#endif

	// TODO: Check whether the theme is used.
	// Get application config.
	cJSON* configs = NULL;
	GhostLogRetIfErr(Fatal, GhostNativeAppGetAppConfigJSON(&configs));

	
	// Theme init.
	GhostLogRetIfErr(Fatal, themeInit());

	// Init pages.
#if(MacroGhostLauncherMemOptimizeLevel != MacroGhostMemOptimizeStrict)
	// Init main page.
	//mainPage = lv_obj_create(lv_scr_act());
#else

#endif

	// TODO: Built in themes.
	// Default theme.
	
	
	while (1)
	{
		mainPageRefresh(mainPage);
	}
	

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


static GhostError_t themeInit()
{

	return GhostOK;
}

static GhostError_t mainPageCreate(lv_obj_t* mainPage)
{


	return GhostOK;
}


static GhostError_t mainPageRefresh(lv_obj_t* mainPage)
{

}


static GhostError_t standbyPageCreate(lv_obj_t* standbyPage)
{

}


static GhostError_t standbyPageRefresh(lv_obj_t* standbyPage)
{

}


