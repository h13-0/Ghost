#include "GhostLauncher.h"

#include "GhostPlatformConfigs.h"

#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "GhostLog.h"
#include "GhostSafeLVGL.h"
#include "GhostApplicationManager.h"
#include "GhostThemeManager.h"

// Drivers
#include "GhostClock.h"
#include "GhostScreen.h"
#include "safe_lvgl.h"

//#include "lv_png.h"

//#include "lodepng.h"

DeclareNativeAppInfo();


static lv_obj_t* mainPage;
static lv_style_t pageStyle;


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

	lv_obj_t* screen;
	GhostLogTerminateIfErr(Fatal, GhostNativeAppGetVirtualScreen(&screen));

	// Init pages.
	// Get screen info.
	int radius;
	GhostLogTerminateIfErr(Fatal, GhostScreenGetRadius(&radius));

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

	// Create main page.
	GhostThemeMgrMainPageCreate(mainPage);

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

	return GhostOK;
}


static GhostError_t standbyPageCreate(lv_obj_t* standbyPage)
{

	return GhostOK;
}


static GhostError_t standbyPageRefresh(lv_obj_t* standbyPage)
{

	return GhostOK;
}


