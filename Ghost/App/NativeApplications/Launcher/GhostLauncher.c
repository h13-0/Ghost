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
static lv_style_t pageStyle;
static lv_style_t bubbleStyle;

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



static lv_obj_t* createPage(lv_obj_t* Screen, lv_color_t BackgroundColor)
{
	// Create page.
	lv_obj_t* page = lv_obj_create(Screen);

	// Init page style.
	lv_obj_set_pos(page, 0, 0);
	lv_obj_set_size(page, GhostScreenGetWidth(), GhostScreenGetHeight());
	lv_obj_add_style(page, &pageStyle, 0);
	lv_obj_set_style_bg_color(page, BackgroundColor, 0);
	return page;
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
	
	// Init main page.
	GhostLV_Lock();

	// Init page style.
	lv_style_init(&pageStyle);
	lv_style_set_border_width(&pageStyle, 0);
	lv_style_set_radius(&pageStyle, radius);

	// Create main page.
	mainPage = createPage(screen, lv_color_black());

	// Tile view?
	// Custom page style.
	lv_obj_clear_flag(mainPage, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_style_pad_all(mainPage, 0, 0);

	// Create scale.
	lv_meter_scale_t* scale = lv_meter_create(mainPage);
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
	if (scaleSize % 2)
	{
		scaleSize++;
	}

	// Set size and pos.
	lv_obj_set_size(scale, scaleSize, scaleSize);
	lv_obj_set_pos(scale, (width - scaleSize) / 2, (height - scaleSize) / 2);

	// Scale style
	lv_color_t centralCircleColor = lv_color_make(223, 223, 223);
	lv_obj_set_style_bg_color(scale, centralCircleColor, 0);
	lv_obj_set_style_border_width(scale, 0, 1);
	lv_obj_set_style_border_color(scale, lv_color_make(227, 227, 227), 0);
	float scalePadSize = scaleSize * 0.015;
	lv_obj_set_style_pad_all(scale, scalePadSize, 0);

	// Set scale.
	// Minute scale.
	lv_meter_scale_t* scale_min = lv_meter_add_scale(scale);
	lv_meter_set_scale_ticks(scale, scale_min, 121, scaleSize * 0.01, ceil(scaleSize * 0.04) - 2, lv_color_make(150, 150, 150));
	lv_meter_set_scale_range(scale, scale_min, 0, 60, 360, 270);

	// Hour scale.
	lv_meter_scale_t* scale_hour = lv_meter_add_scale(scale);
	lv_meter_set_scale_ticks(scale, scale_hour, 12, 0, scaleSize * 0.04, lv_color_black());
	lv_meter_set_scale_major_ticks(scale, scale_hour, 1, scaleSize * 0.01 + 1, scaleSize * 0.04, lv_color_make(30, 30, 30), 10);
	lv_meter_set_scale_range(scale, scale_hour, 1, 12, 330, 300);
	// Disable label.
	lv_obj_set_style_text_opa(scale, 0, 0);
	lv_obj_remove_style(scale, NULL, LV_PART_INDICATOR);
	lv_obj_remove_style(scale, NULL, LV_PART_INDICATOR);

	// hour hand.
	lv_obj_t* hourHand = lv_img_create(mainPage);
	lv_img_set_src(hourHand, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/hour_aw_hand_bl.png");
	lv_img_set_pivot(hourHand, 12, 8.5);
	const float handRatio = (scaleSize * 0.45 * 1.04938) / 175;
	lv_img_set_zoom(hourHand, handRatio * 256);
	lv_img_set_angle(hourHand, 150);
	lv_obj_set_pos(hourHand, width / 2 - 12 - 1, height / 2 - 8.5 - 1);

	// minute hand.
	lv_obj_t* minuteHand = lv_img_create(mainPage);
	lv_img_set_src(minuteHand, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/minute_aw_hand_bl.png");
	lv_img_set_pivot(minuteHand, 8, 10);
	lv_img_set_zoom(minuteHand, handRatio * 256);
	lv_img_set_angle(minuteHand, 300);
	lv_obj_set_pos(minuteHand, width / 2 - 8 - 1, height / 2 - 10 - 1);

	// second hand.
	//float secondHandLength = 0.6 * scaleSize;
	float secondHandFontLength = 0.81 * 0.6 * scaleSize;
	float secondHandBackLength = 0.19 * 0.6 * scaleSize;
	float secondDegree = 60;
	secondDegree = secondDegree / 180 * M_PI;
	lv_point_t secondHandPoints[] = { 
		{ width / 2 + sin(secondDegree) * secondHandFontLength, height / 2 - cos(secondDegree) * secondHandFontLength }, 
		{ width / 2, height / 2},
		{ width / 2 - sin(secondDegree) * secondHandBackLength, height / 2 + cos(secondDegree) * secondHandBackLength }
	};

	lv_obj_t* secondHand = lv_line_create(mainPage);
	lv_obj_set_style_line_color(secondHand, lv_color_make(255, 0, 0), 0);
	lv_obj_set_style_line_width(secondHand, 3, 0);
	lv_line_set_points(secondHand, secondHandPoints, 3);

	// second hand cricle.
	lv_obj_t* secondHandCircle = lv_obj_create(mainPage);
	float secondHandCircleRadius = min(width, height) / 72.0;
	lv_obj_set_size(secondHandCircle, secondHandCircleRadius * 2, secondHandCircleRadius * 2);
	lv_obj_set_pos(secondHandCircle, (width - secondHandCircleRadius) / 2 - 1, (height - secondHandCircleRadius) / 2 - 1);
	lv_obj_set_style_bg_color(secondHandCircle, lv_color_black(), 0);
	lv_obj_set_style_border_color(secondHandCircle, lv_color_make(255, 0, 0), 0);
	lv_obj_set_style_border_width(secondHandCircle, secondHandCircleRadius / 2, 0);

	// Bubbles
	// set style.
	lv_style_init(&bubbleStyle);
	int bubbleSize = scaleSize * 0.287;
	if (bubbleSize % 2)
	{
		bubbleSize += 3;
	}
	else
	{
		bubbleSize += 2;
	}

	lv_style_set_bg_color(&bubbleStyle, lv_color_make(22, 22, 22));
	lv_style_set_radius(&bubbleStyle, bubbleSize / 2);
	lv_style_set_size(&bubbleStyle, bubbleSize);
	lv_style_set_border_color(&bubbleStyle, lv_color_make(255, 255, 255));
	lv_style_set_border_opa(&bubbleStyle, 50);
	int bubblePad = (bubbleSize * 0.05 + 0.5); //rounding.
	int bubbleBorderWidth = ceil(bubbleSize * 0.01);
	lv_style_set_pad_all(&bubbleStyle, bubblePad);
	lv_style_set_border_width(&bubbleStyle, bubbleBorderWidth);

	float bubbleMargin = scaleSize * 0.12037;
	float bubbleToEdge = bubbleMargin - scalePadSize - 2;
	float bubbleToCenter = (scaleSize - bubbleSize) / 2 - scalePadSize - 1;
	lv_obj_t* bubbleUp = lv_obj_create(scale);
	lv_obj_add_style(bubbleUp, &bubbleStyle, 0);
	lv_obj_set_pos(bubbleUp, bubbleToCenter, bubbleToEdge);
	lv_obj_set_scrollbar_mode(bubbleUp, LV_SCROLLBAR_MODE_OFF);

	lv_obj_t* bubbleDown = lv_obj_create(scale);
	lv_obj_add_style(bubbleDown, &bubbleStyle, 0);
	lv_obj_set_pos(bubbleDown, bubbleToCenter, scaleSize - bubbleMargin - scalePadSize + 1 - bubbleSize);
	lv_obj_set_scrollbar_mode(bubbleDown, LV_SCROLLBAR_MODE_OFF);

	lv_obj_t* bubbleLeft = lv_obj_create(scale);
	lv_obj_add_style(bubbleLeft, &bubbleStyle, 0);
	lv_obj_set_pos(bubbleLeft, bubbleToEdge, bubbleToCenter);
	lv_obj_set_scrollbar_mode(bubbleLeft, LV_SCROLLBAR_MODE_OFF);
	
	lv_obj_t* bubbleRight = lv_obj_create(scale);
	lv_obj_add_style(bubbleRight, &bubbleStyle, 0);
	lv_obj_set_pos(bubbleRight, scaleSize * 0.87963 - scalePadSize + 1 - bubbleSize, bubbleToCenter);
	lv_obj_set_scrollbar_mode(bubbleRight, LV_SCROLLBAR_MODE_OFF);

	// Set bubble images.


	// earth.
	lv_obj_t* earthImg = lv_img_create(bubbleLeft);
	lv_img_header_t header;
	lv_img_decoder_get_info("C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/earth.png", &header);
	lv_img_set_src(earthImg, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/earth.png");
	lv_img_set_pivot(earthImg, -1, -1); //I don't know why..
	lv_img_set_zoom(earthImg, (256 * (bubbleSize - 2 * (bubblePad + bubbleBorderWidth)) / min(header.w, header.h) + 0.5));
	
	
	//lv_obj_set_style_bg_img_src(earthImg, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/earth.png", 0);

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


