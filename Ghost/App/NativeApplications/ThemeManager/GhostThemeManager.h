#pragma once

#include "GhostSoftwareErrorDefine.h"

#include "safe_lvgl.h"

#include "GhostTheme.h"

#define GhostErrorThemeMgrUninitialized                     DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 1)
#define GhostErrorThemeMgrAlreadyInitialized                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 2)
#define GhostErrorThemeMgrOutOfMemory                       DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 3)
#define GhostErrorThemeMgrNoThemeSelected                   DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 4)
#define GhostErrorThemeMgrPageUninitialized                 DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 5)
#define GhostErrorThemeMgrDuplicatePackageName              DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 6)
#define GhostErrorThemeMgrThemeUninitialized                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 7)
#define GhostErrorThemeMgrRefreshFailed                     DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 8)

/*


#define GhostErrorThemeMgrThemeConfigFileMissing            DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 8)
#define GhostErrorThemeMgrThemeConfigIllegal                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 9)
#define GhostErrorThemeMgrThemeInitializationFailed         DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 10)
*/

#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// Init Ghost theme manager.
	/// </summary>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrRun(void);


	/// <summary>
	/// Register built-in theme.
	/// </summary>
	/// <param name="Theme">Theme handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrRegeisterBuiltInTheme(GhostTheme_t* Theme);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="PackageName"></param>
	/// <param name="Theme"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrRegeisterThirdpartyTheme(char* PackageName, GhostTheme_t* Theme);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="Theme"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrUnistallTheme(GhostTheme_t* Theme);
	

	typedef struct
	{
		char* CurrentMainPage;

	} GhostThemeMgrCurrentThemeInfo_t;

	GhostError_t GhostThemeMgrGetCurrentTheme(GhostThemeMgrCurrentThemeInfo_t*Info);


	/// <summary>
	/// Create main page.
	///		This function should be called in GhostLaucher.
	/// </summary>
	/// <param name="MainPage">Main page handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrMainPageCreate(lv_obj_t* MainPage);


	/// <summary>
	/// Refresh main page.
	/// 	This function should be called in GhostLaucher.
	/// </summary>
	/// <param name="MainPage">Main page handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrMainPageRefresh(lv_obj_t* MainPage);


	/// <summary>
	/// Get the minimum refresh period of main page.
	///		Thread safe:
	///			Yes.
	///		Note:
	///			Refresh period refers to the refresh rate of the material or control value, not the actual screen refresh rate.
	///			This value is the cycle of `MainPageRefresh` handle being called.
	///			The actual screen refresh rate depends on the macro `MacroScreenRefreshRate`.
	///			Therefore, the refresh cycle need not be too small.
	///			The default value is 500.
	/// </summary>
	/// <returns>Minimum refresh period of main page.</returns>
	int GhostThemeMgrGetMainPageMinimumRefreshPeriod(void);


	/// <summary>
	/// Set refresh period of main page.
	///		The default value of period is 500.
	///		Period should be greater than return value of GhostThemeMgrGetMainPageMinimumRefreshPeriod().
	///		It will be set to the minimum value if RefreshPeriod is less than minimum value.
	/// </summary>
	/// <param name="Milliseconds">Refresh period of main page in milliseconds.</param>
	/// <returns>Actually set refresh cycle.</returns>
	int GhostThemeMgrSetMainPageRefreshPeriod(int Milliseconds);


	/// <summary>
	/// Create AppList page.
	///		This function should be called in GhostLaucher.
	/// </summary>
	/// <param name="AppListPage">AppList page handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrAppListPageCreate(lv_obj_t* AppListPage);


	/// <summary>
	/// Refresh AppList page.
	/// 	This function should be called in GhostLaucher.
	/// </summary>
	/// <param name="MainPage">Main page handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrAppListPageRefresh(lv_obj_t* AppListPage);


#ifdef __cplusplus
}
#endif
