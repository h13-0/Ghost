#pragma once

#include "safe_lvgl.h"

// Drivers.
#include "GhostLog.h"
#include "GhostScreen.h"
#include "GhostMemoryManager.h"
#include "GhostClock.h"

#include "GhostSoftwareErrorDefine.h"



// Common errors.
#define GhostErrorThemeNotRegistered                                    DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 1)
#define GhostErrorThemeResourcePointorDuplicate                         DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 2)
#define GhostErrorThemeParameterIllegal                                 DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 3)
#define GhostErrorThemeCreatePageFailed                                 DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 4)
#define GhostErrorThemeRefreshPageFailed                                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 5)
#define GhostErrorThemeOutOfMemory                                      DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 6)
#define GhostErrorThemeInappropriateResolution                          DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 7)
#define GhostErrorThemeResourceLost                                     DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 8)
#define GhostErrorThemeOperationTimeOut                                 DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeError, 9)

#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// Typedef of GhostTheme_t.
	///		Thread safety is not required during theme development.
	/// </summary>
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
		GhostError_t(*MainPageCreate)(lv_obj_t* MainPage, void* ResourcePtr);


		/// <summary>
		/// Main page (home page) refresh handle.
		/// </summary>
		/// <param name="MainPage">Pointor of main page.</param>
		/// <returns>If the return value is not GhostOK, **this page** will be reset to the default theme.</returns>
		GhostError_t(*MainPageRefresh)(lv_obj_t* MainPage, void* ResourcePtr);


		/// <summary>
		/// Standby page (always-on page) theme initialization.
		/// </summary>
		/// <param name="standbyPage"></param>
		/// <returns>If the return value is not GhostOK, **this page** will be reset to the default theme.</returns>
		GhostError_t(*StandbyPageCreate)(lv_obj_t* StandbyPage, void* ResourcePtr);


		/// <summary>
		/// Standby page (always-on page) refresh handle.
		/// </summary>
		/// <param name="standbyPage"></param>
		/// <returns>If the return value is not GhostOK, **this page** will be reset to the default theme.</returns>
		GhostError_t(*StandbyPageRefresh)(lv_obj_t* StandbyPage, void* ResourcePtr);


		/// <summary>
		/// Theme init.
		///		All pages **SHOULD NOT** be initialized in this function.
		///		You need to set the screen refresh period in this function.
		/// </summary>
		/// <returns>Function execution result.</returns>
		GhostError_t(*ThemeDestory)(void);

		// 
	} GhostTheme_t;

#define DeclareNativeThemeInfo(PackageName)                             static const char* __packageName__ = PackageName


	/// <summary>
	/// Set and register resource pointer.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <param name="ResourcePtr">Pointor of resource.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeSetResourcePointor(const char* PackageName, const void* ResourcePtr);
#define GhostNativeThemeSetResourcePointor(ResourcePtr)                 GhostThemeSetResourcePointor(__packageName__, ResourcePtr)


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
	int GhostThemeGetMainPageMinimumRefreshPeriod(const char* PackageName);
#define GhostNativeThemeGetMainPageMinimumRefreshPeriod()               GhostThemeGetMainPageMinimumRefreshPeriod(__packageName__)


	/// <summary>
	/// Set refresh period of main page.
	///		The default value of period is 500.
	///		Period should be greater than return value of GhostThemeMgrGetMainPageMinimumRefreshPeriod().
	///		It will be set to the minimum value if RefreshPeriod is less than minimum value.
	/// </summary>
	/// <param name="Milliseconds">Refresh period of main page in milliseconds.</param>
	/// <returns>Actually set refresh cycle.</returns>
	int GhostThemeSetMainPageRefreshPeriod(const char* PackageName, int Milliseconds);
#define GhostNativeThemeSetMainPageRefreshPeriod(Milliseconds)          GhostThemeSetMainPageRefreshPeriod(__packageName__, Milliseconds)


	// Drivers api.
	/// Screen.
#define GhostNativeThemeGetResolution(Width, Height)                    GhostScreenGetResolution(Width, Height)
#define GhostNativeThemeGetRadius(Radius)                               GhostScreenGetRadius(Radius)

	/// Memory manager.
#define GhostNativeThemeMemMalloc(Size)                                 GhostMemMgrMalloc(Size)
#define GhostNativeThemeMemCalloc(Count, Size)                          GhostMemMgrCalloc(Count, Size)
#define GhostNativeThemeMemFree(Size)                                   GhostMemMgrFree(Size)

	/// Clock.
#define GhostNativeThemeGetCurrentTime(Hour, Minute, Second)            GhostGetCurrentTime(Hour, Minute, Second)
#define GhostNativeThemeGetCurrentMilliseconds(Milliseconds)            GhostGetCurrentMilliseconds(Milliseconds)    

#ifdef __cplusplus
}
#endif
