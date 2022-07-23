#pragma once

#include "GhostSoftwareErrorDefine.h"


#include "safe_lvgl.h"


#define GhostErrorThemeMgrUninitialized                     DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 1)
#define GhostErrorThemeMgrThemeUninitialized                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 2)
#define GhostErrorThemeMgrThemeConfigFileMissing            DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 3)
#define GhostErrorThemeMgrThemeConfigIllegal                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 4)
#define GhostErrorThemeMgrThemeInitializationFailed         DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 5)

#ifdef __cplusplus
extern "C" {
#endif


	/// <summary>
	/// Typedef of GhostTheme_t.
	/// </summary>
	typedef struct {
		// Basic informations.
		char* PackageName;
		char* ThemeName;
		int Version;

		// Function handles.
		/// <summary>
		/// Theme init.
		///		All pages **SHOULD NOT** be initialized in this function.
		///		You need to set the screen refresh period in this function.
		/// </summary>
		/// <returns>If the return value is not GhostOK, it will be reset to the default theme.</returns>
		GhostError_t(*ThemeInit)(void);


		/// <summary>
		/// Theme init.
		///		All pages **SHOULD NOT** be initialized in this function.
		///		You need to set the screen refresh period in this function.
		/// </summary>
		/// <returns>Function execution result.</returns>
		GhostError_t(*ThemeDestory)(void);
	} GhostTheme_t;


	/// <summary>
	/// Init Ghost theme manager.
	/// </summary>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrInit(void);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="PackageName"></param>
	/// <param name="Theme"></param>
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
	/// Function handles of main page.
	///		If the return value is not GhostOK, the theme of this page will be replaced with the default theme.
	/// </summary>
	typedef GhostError_t(*PageCreateHandle_t)(lv_obj_t* Page);
	typedef GhostError_t(*PageRefreshHandle_t)(lv_obj_t* Page);


	/// <summary>
	/// Set main page function handle.
	///		Period should be greater than return value of GhostThemeMgrGetMainPageMinimumRefreshPeriod();.
	///		It will be set to the minimum value if RefreshPeriod is less than minimum value.
	/// </summary>
	/// <param name="MainPageCreateHandle">Pointor of main page create function in PageCreateHandle_t.</param>
	/// <param name="MainPageRefreshHandle">Pointor of main page refresh function in PageRefreshHandle_t.</param>
	/// <param name="RefreshPeriod">Refresh period of main page in millisecond.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrSetMainPageHandle(PageCreateHandle_t MainPageCreateHandle, PageRefreshHandle_t MainPageRefreshHandle, int RefreshPeriod);


	/// <summary>
	/// Get the minimum refresh period of main page.
	///		The default value is 1000.
	/// </summary>
	/// <returns>Minimum refresh period of main page.</returns>
	int GhostThemeMgrGetMainPageMinimumRefreshPeriod(void);


	/// <summary>
	/// Set refresh period of main page.
	///		The default value of period is 1000.
	///		Period should be greater than return value of GhostThemeMgrGetMainPageMinimumRefreshPeriod().
	///		It will be set to the minimum value if RefreshPeriod is less than minimum value.
	/// </summary>
	/// <param name="Period">Refresh period of main page in second.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrSetMainPageRefreshPeriod(int Period);




	/// <summary>
	/// 
	/// </summary>
	/// <param name="Theme"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeMgrUnistallTheme(GhostTheme_t* Theme);
	


	



#ifdef __cplusplus
}
#endif
