#pragma once

#include "GhostSoftwareErrorDefine.h"

#include "safe_lvgl.h"

#include "GhostTheme.h"

#define GhostErrorThemeMgrUninitialized                     DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 1)
#define GhostErrorThemeMgrAlreadyInitialized                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 2)
#define GhostErrorThemeMgrOutOfMemory                       DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 3)

#define GhostErrorThemeMgrThemeDuplicatePackageName         DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 4)
#define GhostErrorThemeMgrThemeUninitialized                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 5)
#define GhostErrorThemeMgrThemeRefreshFailed                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 6)
#define GhostErrorThemeMgrThemeConfigFileMissing            DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 7)
#define GhostErrorThemeMgrThemeConfigIllegal                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 8)
#define GhostErrorThemeMgrThemeInitializationFailed         DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 9)

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

	} GhostThemeMgrCurrentTheme_t;

	GhostThemeMgrCurrentTheme_t GhostThemeMgrGetCurrentTheme(void);


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

#ifdef __cplusplus
}
#endif
