#include "GhostThemeManager.h"

typedef struct {
	// Basic informations.
	char* PackageName;
	char* ThemeName;
	int Version;

	// Function handles.
	/// <summary>
	/// Theme init.
	/// All pages **SHOULD NOT** be initialized in this function.
	/// You need to set the screen refresh period in this function.
	/// </summary>
	/// <returns>If the return value is not GhostOK, it will be reset to the default theme.</returns>
	GhostError_t(*ThemeInit)(void);


	/// <summary>
	/// Main page (home page) theme initialization.
	/// </summary>
	/// <param name="MainPage">Pointor of main page.</param>
	/// <returns>If the return value is not GhostOK, **this page** will be reset to the default theme.</returns>
	GhostError_t(*MainPageCreate)(lv_obj_t* MainPage);


	/// <summary>
	/// Main page (home page) refresh handle.
	/// </summary>
	/// <param name="MainPage">Pointor of main page.</param>
	/// <returns>If the return value is not GhostOK, **this page** will be reset to the default theme.</returns>
	GhostError_t(*MainPageRefresh)(lv_obj_t* MainPage);


	/// <summary>
	/// Standby page (always-on page) theme initialization.
	/// </summary>
	/// <param name="standbyPage"></param>
	/// <returns>If the return value is not GhostOK, **this page** will be reset to the default theme.</returns>
	GhostError_t(*StandbyPageCreate)(lv_obj_t* StandbyPage);


	/// <summary>
	/// Standby page (always-on page) refresh handle.
	/// </summary>
	/// <param name="standbyPage"></param>
	/// <returns>If the return value is not GhostOK, **this page** will be reset to the default theme.</returns>
	GhostError_t(*StandbyPageRefresh)(lv_obj_t* StandbyPage);


	// Init
	// Destory

	// 
} GhostThemeHandle_t;


/// <summary>
/// Init Ghost theme manager.
/// </summary>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrInit(void)
{

}
