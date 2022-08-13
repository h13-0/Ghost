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

typedef struct
{
	lv_style_t PageStyle;
	lv_obj_t* TileView;
	lv_obj_t* MainPage;
	lv_obj_t* AppListPage;

} GhostLauncher_t;

static GhostLauncher_t* launcher = NULL;

static lv_obj_t* createPage(lv_color_t BackgroundColor, uint8_t ColID, uint8_t RowID, lv_dir_t Dir)
{
	// Create page.
	lv_obj_t* page = lv_tileview_add_tile(launcher->TileView, ColID, RowID, Dir);

	// Init page style.
	//lv_obj_set_pos(page, 0, 0);
	lv_obj_set_size(page, GhostScreenGetWidth(), GhostScreenGetHeight());
	lv_obj_add_style(page, &launcher->PageStyle, 0);
	//lv_obj_set_style_bg_color(page, BackgroundColor, 0);
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

	// Check whether the initialization is repeated.
	if (launcher != NULL)
	{
		GhostLogF("Ghost Launcher already initialized.");
		return GhostErrorLauncherMgrAlreadyInitialized;
	}

	// Allocate memory.
	launcher = GhostMemMgrCalloc(1, sizeof(GhostLauncher_t));
	if (launcher == NULL)
	{
		GhostLogF("Out Of Memory!");
		return GhostErrorLauncherMgrOutOfMemory;
	}

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
	GhostLV_Lock();
	lv_style_init(&launcher->PageStyle);
	lv_style_set_border_width(&launcher->PageStyle, 0);
	lv_style_set_radius(&launcher->PageStyle, radius);

	launcher->TileView = lv_tileview_create(screen);
	lv_obj_set_style_bg_color(launcher->TileView, lv_color_black(), 0);
	

	launcher->MainPage = createPage(lv_color_black(), 0, 0, LV_DIR_BOTTOM);
	launcher->AppListPage = createPage(lv_color_black(), 0, 1, LV_DIR_TOP | LV_DIR_RIGHT);

	//while (1);

	// Create main page.
	//mainPage = createPage(screen, lv_color_black());

	// Tile view?
	// Custom page style.
	lv_obj_clear_flag(launcher->MainPage, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_style_pad_all(launcher->MainPage, 0, 0);
	GhostLV_Unlock();

	// Create main page.
	GhostThemeMgrMainPageCreate(launcher->MainPage);
	



	// TODO: Built in themes.
	// Default theme.
	
	
	while (1)
	{


		GhostThemeMgrMainPageRefresh(launcher->MainPage);
		GhostSleepMillisecond(GhostThemeMgrGetMainPageMinimumRefreshPeriod());
	}
	
	return GhostOK;
}

