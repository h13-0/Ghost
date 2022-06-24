#include "GhostLauncher.h"

#include "GhostPlatformConfigs.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "GhostLog.h"
#include "GhostSafeLVGL.h"
#include "GhostApplicationManager.h"

// Drivers
#include "GhostClock.h"
#include "GhostScreen.h"
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

	lv_obj_t* screen;
	GhostLogRetIfErr(Fatal, GhostNativeAppGetVirtualScreen(&screen));

	// Init pages.
	// Get screen info.
	int width, height, radius;
	GhostLogRetIfErr(Fatal, GhostScreenGetResolution(&width, &height));
	GhostLogRetIfErr(Fatal, GhostScreenGetRadius(&radius));

	// Init page style.
	lv_style_t pageStyle;
	lv_style_init(&pageStyle);
	lv_style_set_border_width(&pageStyle, 0);
	lv_style_set_radius(&pageStyle, radius);
	
	// Init main page.
	GhostLV_Lock();
	// Create main page.
	mainPage = lv_obj_create(screen);
	
	// Tile view?
	// Init page style.
	lv_obj_set_pos(mainPage, 0, 0);
	lv_obj_set_size(mainPage, width, height);
	lv_obj_add_style(mainPage, &pageStyle, 0);
	lv_obj_set_style_bg_color(mainPage, lv_color_black(), 0);
	lv_obj_clear_flag(mainPage, LV_OBJ_FLAG_SCROLLABLE);

	// Create scale.
	lv_meter_scale_t* scale = lv_meter_create(mainPage, NULL);
	int minWH = min(width, height);
	int maxWH = max(width, height);
	int margin = minWH / 20;
	
	int scaleSize = 0;
	if (height - 2 * margin > minWH)
	{
		scaleSize = minWH;
	}
	else {
		scaleSize = height - margin * 2;
	}

	// Set size and pos.
	lv_obj_set_size(scale, scaleSize, scaleSize);
	lv_obj_set_pos(scale, 0, (height - scaleSize) / 2 - margin);

	// Scale style
	lv_color_t centralCircleColor = lv_color_make(255, 255, 253);
	lv_obj_set_style_bg_color(scale, centralCircleColor, 0);
	lv_obj_set_style_border_color(scale, centralCircleColor, 0);
	lv_obj_set_style_border_opa(scale, 50, 0);
	lv_obj_set_style_pad_all(scale, scaleSize * 0.015, 0);

	// Set scale.
	// Minute scale.
	lv_meter_scale_t* scale_min = lv_meter_add_scale(scale);
	lv_meter_set_scale_ticks(scale, scale_min, 61, scaleSize * 0.01, ceil(scaleSize * 0.04) - 2, lv_color_make(150, 150, 150));
	lv_meter_set_scale_range(scale, scale_min, 0, 60, 360, 270);

	// Hour scale.
	lv_meter_scale_t* scale_hour = lv_meter_add_scale(scale);
	lv_meter_set_scale_ticks(scale, scale_hour, 12, 0, scaleSize * 0.04, lv_color_black());
	lv_meter_set_scale_major_ticks(scale, scale_hour, 1, scaleSize * 0.01 + 1, ceil(scaleSize * 0.04), lv_color_black(), 10);
	lv_meter_set_scale_range(scale, scale_hour, 1, 12, 330, 300);
	// Disable label.
	lv_obj_set_style_text_opa(scale, 0, 0);
	lv_obj_remove_style(scale, NULL, LV_PART_INDICATOR);
	lv_obj_remove_style(scale, NULL, LV_PART_INDICATOR);

	//
	//lv_meter_indicator_t* indic_min = lv_meter_add_needle_img(scale, scale_min, NULL, 5, 5);
	//lv_meter_indicator_t* indic_hour = lv_meter_add_needle_img(scale, scale_min, &img_hand, 5, 5);
	

	GhostLV_Unlock();

	// TODO: Built in themes.
	// Default theme.
	
	
	while (1)
	{
		mainPageRefresh(mainPage);
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


