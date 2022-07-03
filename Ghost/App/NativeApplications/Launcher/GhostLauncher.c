#include "GhostLauncher.h"

#include "GhostPlatformConfigs.h"

#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "GhostLog.h"
#include "GhostSafeLVGL.h"
#include "GhostApplicationManager.h"

// Drivers
#include "GhostClock.h"
#include "GhostScreen.h"
#include "safe_lvgl.h"

//#include "lv_png.h"

//#include "lodepng.h"

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

static void set_zoom(void* img, int32_t v)
{
	lv_img_set_zoom(img, v);
}


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
	//GhostLogTerminateIfErr(Fatal, GhostNativeAppGetAppConfigJSON(&configs));

	
	// Theme init.
	GhostLogTerminateIfErr(Fatal, themeInit());

	lv_obj_t* screen;
	GhostLogTerminateIfErr(Fatal, GhostNativeAppGetVirtualScreen(&screen));

	// Init pages.
	// Get screen info.
	int width, height, radius;
	GhostLogTerminateIfErr(Fatal, GhostScreenGetResolution(&width, &height));
	GhostLogTerminateIfErr(Fatal, GhostScreenGetRadius(&radius));


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

	// hour hand.
	lv_obj_t* hourHand = lv_img_create(screen);
	lv_img_set_src(hourHand, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/hour_aw_hand_bl.png");
	lv_img_set_pivot(hourHand, 12, 8.5);
	const float handRatio = (scaleSize * 0.45 * 1.04938) / 175;
	lv_img_set_zoom(hourHand, handRatio * 256);
	lv_img_set_angle(hourHand, 150);
	lv_obj_set_pos(hourHand, width / 2 - 12, height / 2 - 8.5);

	// minute hand.
	lv_obj_t* minuteHand = lv_img_create(screen);
	lv_img_set_src(minuteHand, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/minute_aw_hand_bl.png");
	lv_img_set_pivot(minuteHand, 8, 10);
	lv_img_set_zoom(minuteHand, handRatio * 256);
	lv_img_set_angle(minuteHand, 300);
	lv_obj_set_pos(minuteHand, width / 2 - 8, height / 2 - 10);

	// second hand.
	//float secondHandLength = 0.6 * scaleSize;
	float secondHandFontLength = 0.81 * 0.6 * scaleSize;
	float secondHandBackLength = 0.19 * 0.6 * scaleSize;
	float secondDegree = 60;
	secondDegree = secondDegree / 180 * M_PI;
	lv_point_t secondHandPoints[] = { 
		{ width / 2 + sin(secondDegree) * secondHandFontLength + 1, height / 2 - cos(secondDegree) * secondHandFontLength + 1 }, 
		{ width / 2 + 1, height / 2 + 1},
		{ width / 2 - sin(secondDegree) * secondHandBackLength + 1, height / 2 + cos(secondDegree) * secondHandBackLength + 1 }
	};

	lv_obj_t* secondHand = lv_line_create(screen);
	lv_obj_set_style_line_color(secondHand, lv_color_make(255, 0, 0), 0);
	lv_obj_set_style_line_width(secondHand, 3, 0);
	lv_line_set_points(secondHand, secondHandPoints, 3);

	// second hand cricle.
	lv_obj_t* secondHandCircle = lv_obj_create(screen);
	float secondHandCircleRadius = min(width, height) / 72.0;
	lv_obj_set_size(secondHandCircle, secondHandCircleRadius * 2, secondHandCircleRadius * 2);
	lv_obj_set_pos(secondHandCircle, (width - secondHandCircleRadius) / 2, (height - secondHandCircleRadius) / 2);
	//lv_style_set_radius(secondHandCircle, secondHandCircleRadius);
	lv_obj_set_style_bg_color(secondHandCircle, lv_color_make(255, 0, 0), 0);
	if (secondHandCircleRadius > 3)
	{
		lv_obj_set_style_border_width(secondHandCircle, 1, 0);
		lv_obj_set_style_border_opa(secondHandCircle, 50, 0);
		lv_obj_set_style_border_color(secondHandCircle, lv_color_make(215, 40, 40), 0);
	}
	else {
		lv_obj_set_style_border_width(secondHandCircle, 0, 0);
	}
	
	




	//lv_img_set_src(&min_img, );
	//lv_img_set_src(min_img, );
	//lv_img_set_zoom(min_img, 128);

	/*
	lv_anim_t a;
	lv_anim_init(&a);
	lv_anim_set_var(&a, min_img);
	lv_anim_set_values(&a, 0, 3600);
	lv_anim_set_time(&a, 5000);
	lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
	lv_anim_start(&a);

	lv_anim_set_exec_cb(&a, set_zoom);
	lv_anim_set_values(&a, 128, 256);
	lv_anim_set_playback_time(&a, 3000);
	lv_anim_start(&a);
	*/
	// 
	
	

	
	
	//lv_meter_indicator_t* indic_hour = lv_meter_add_needle_img(scale, scale_min, &img_hand, 5, 5);

	//lv_meter_indicator_t* indic_min = lv_meter_add_needle_img(scale, scale_min, NULL, 5, 5);
	//lv_meter_indicator_t* indic_min = lv_meter_add_needle_line(scale, scale_min, 3, lv_color_black(), 10);


	GhostLV_Unlock();

	// TODO: Built in themes.
	// Default theme.
	
	
	while (1)
	{
		mainPageRefresh(mainPage);
		GhostSleepMillisecond(10);
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


