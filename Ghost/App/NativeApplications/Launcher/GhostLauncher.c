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
	lv_style_t pageStyle;
	lv_style_init(&pageStyle);
	lv_style_set_border_width(&pageStyle, 0);
	lv_style_set_radius(&pageStyle, MacroDisplayFilletRadius);
	

	// Init main page.
	GhostLV_Lock();
	mainPage = lv_obj_create(lv_scr_act());
	//lv_obj_remove_style_all(mainPage);
	lv_obj_set_pos(mainPage, 0, 0);
	lv_obj_set_size(mainPage, MacroDisplayHorizontalResolution, MacroDisplayVerticalResolution / 2);
	lv_obj_add_style(mainPage, &pageStyle, 0);
	lv_obj_set_style_bg_color(mainPage, lv_color_black(), 0);
	GhostLV_Unlock();
#else

#endif

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


