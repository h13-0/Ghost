#include "GhostThemeManager.h"
#include "GhostPlatformConfigs.h"

// Standard libs.
#include <stddef.h>
#include <stdbool.h>

// ThirdPartys.
#include "list.h"

// Drivers.
#include "GhostMemoryManager.h"
#include "GhostLog.h"
#include "GhostThread.h"

// Application manager.
//#include "GhostApplicationManager.h"
#include "GhostPlatformConfigs.h"

#include "GhostThemeHandle.h"

// Built-in themes.
#include "GhostTheme.h"
#include "GhostAppleInfograph.h"


/// <summary>
/// Typedef struct of GhostThemeManager.
/// </summary>
typedef struct {
	// Mutex.
	GhostMutex_t Mutex;

	// Basic configs.
	unsigned int MainPageRefreshPeriod;

	// Linked list.
	list_t* Themes;

	// Current theme.
	GhostThemeHandle_t* MainPageThemeHandle;
	GhostThemeHandle_t* AppDrawerPageThemeHandle;

	// Theme manager status.
	bool ThemeManagerLoaded : 1;

} GhostThemeManager_t;


// Pointor of GhostThemeManager_t.
static GhostThemeManager_t* manager = NULL;

// Static functions.
MacroStatic GhostError_t ghostBuiltInThemeRegister(void);
MacroStatic GhostThemeHandle_t* ghostThemeFindHandleByPackageName(const char* PackageName);
MacroStatic GhostError_t ghostThemeMgrPageCreate(lv_obj_t* TargetPage, GhostThemePage_t* PageHandle);
MacroStatic GhostError_t setDefaultTheme(const char* PackageName);

/// <summary>
/// Register built-in themes.
///		This function will be called automatically after the initialization of the manager is completed.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
MacroStaticInline GhostError_t ghostBuiltInThemeRegister(void)
{
	// Apple info graph(tech.h13.ghost.theme.appleinfograph)
#if defined(MacroGhostThemeAppleInfograph)
	GhostTheme_t appleInfograph = { 0 };
	appleInfograph.ThemeName = MacroGhostThemeAppleInfographName;
	appleInfograph.PackageName = MacroGhostThemeAppleInfograph;
	appleInfograph.Version = MacroGhostThemeAppleInfographVersion;
	appleInfograph.ThemeInit = MacroGhostThemeAppleInfographInitFunction;
	appleInfograph.ThemeDestory = MacroGhostThemeAppleInfographDestoryFunction;

	// Main page:
	appleInfograph.MainPage.Create = MacroGhostThemeAppleInfographMainPageCreateFunction;
	appleInfograph.MainPage.Refresh = MacroGhostThemeAppleInfographMainPageRefreshFunction;

	// AppDrawer page:
	appleInfograph.AppDrawerPage.Create = MacroGhostThemeAppleInfographAppDrawerPageCreateFunction;
	GhostLogTerminateIfErr(Fatal, GhostThemeMgrRegeisterBuiltInTheme(&appleInfograph));
#endif

	// Other themes...


}


/// <summary>
/// Init Ghost theme manager.
/// </summary>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrRun(void)
{
	// Initialize application information.
	GhostAppNativeInfoInit(MacroGhostThemeManagerPackageName);

	// Check whether the initialization is repeated.
	if (manager != NULL)
	{
		GhostLogF("Ghost ThemeManager already initialized.");
		return GhostErrorThemeMgrAlreadyInitialized;
	}

	// Allocate memory.
	manager = GhostMemMgrCalloc(1, sizeof(GhostThemeManager_t));
	if (manager == NULL)
	{
		GhostLogF("Out Of Memory!");
		return GhostErrorThemeMgrOutOfMemory;
	}

	// Init mutex.
	GhostLogTerminateIfErr(Fatal, GhostMutexInit(&manager->Mutex));

	GhostMutexLock(&manager->Mutex);
	// Init basic configs.
	manager->MainPageRefreshPeriod = MacroGhostThemeManagerMainPageMinimumRefreshPeriod;

	// Init theme linked list.
	manager->Themes = list_new();
	manager->Themes->match = GhostThemeHandleMatch;
	manager->Themes->free = GhostThemeHandleDestory;

	// Check whether initialization is successful.
	if (manager->Themes == NULL)
	{
		GhostMutexUnlock(&manager->Mutex);
		GhostLogF("Ghost Theme Manager initialized failed, out of memory!");
		GhostMemMgrFree(manager);
		return GhostErrorThemeMgrOutOfMemory;
	}

	// Output log.
	GhostLogI("Ghost Theme Manager initialized successfully.");
	GhostLogI("Loading built-in themes...");

	// Register built-in themes.
	GhostError_t ret = ghostBuiltInThemeRegister();
	if (IfGhostError(ret))
	{
		GhostMutexUnlock(&manager->Mutex);
		GhostLogE("Built in theme loading failed.");
		return ret;
	}

	GhostLogI("Successfully loaded %d native themes and %d third-party themes.", 0, 0);

	// Select default theme.
#if defined(MacroGhostLauncherDefaultTheme)
	ret = setDefaultTheme(MacroGhostLauncherDefaultTheme);
	if (IfGhostError(ret))
	{
		GhostMutexUnlock(&manager->Mutex);
		return ret;
	}
#else
	// TODO:
	// Select original theme.
#endif

	GhostMutexUnlock(&manager->Mutex);
	return GhostOK;
	// If foreground...
}


/// <summary>
/// Register built-in theme.
/// </summary>
/// <param name="Theme">Theme handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrRegeisterBuiltInTheme(GhostTheme_t* ThemeInfo)
{
	// Make theme handle.
	GhostThemeHandle_t* handle = GhostThemeMgrThemeHandleCreate(ThemeInfo);
	if (handle == NULL)
	{
		GhostLogE("Regeister built-in theme failed, out of memory!");
		return GhostErrorThemeMgrOutOfMemory;
	}

	// Make sure the theme is not registered twice.
	/// TODO: Dichotomy.
	//// But is the linked list really suitable for dichotomy?
	if (!list_find(manager->Themes, handle))
	{
		// Push.
		list_rpush(manager->Themes, list_node_new(handle));
	}
	else {
		GhostLogE("Duplicate PackageName.");
		return GhostErrorThemeMgrDuplicatePackageName;
	}
	return GhostOK;
}


/// <summary>
/// Set main page theme.
///		Thread safe:
///			Yes.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrSetMainPageTheme(char* PackageName)
{
	GhostThemeHandle_t *handle = ghostThemeFindHandleByPackageName(PackageName);
	if (handle == NULL)
	{
		return GhostErrorThemeMgrPackageNotFound;
	}

	// Create page.

	if(false) //failed
	{
		if (manager->MainPageThemeHandle == NULL)
		{
			// Use security theme.
		}
		else {
			// Use current theme.
			// Output error information to UI.

		}
	}
	else {
		// Create page success.
		manager->MainPageThemeHandle = handle;
	}
}


/// <summary>
/// Set and register resource pointer.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="ResourcePtr">Pointor of resource.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeSetResourcePointor(const char* PackageName, const void* ResourcePtr)
{
	// Check parameter.
	if (ResourcePtr == NULL)
	{
		return GhostErrorThemeParameterIllegal;
	}

	// Check strlen.
	if (strlen(PackageName) > MacroGhostLogMaximumContentsSize - 38)
	{
		return GhostErrorThemeParameterIllegal;
	}

	GhostError_t ret = GhostOK;
	GhostThemeHandle_t* handle = ghostThemeFindHandleByPackageName(PackageName);
	if (handle == NULL)
	{
		GhostLogE("Theme: %s not registered.", PackageName);
		ret = GhostErrorThemeNotRegistered;
	}
	else {
		if (handle->Resources != NULL)
		{
			GhostLogE("Theme: %s resource pointor duplicate.", PackageName);
			ret = GhostErrorThemeResourcePointorDuplicate;
		}
		else {
			handle->Resources = ResourcePtr;
		}
	}

	return ret;
}


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
int GhostThemeMgrGetMainPageMinimumRefreshPeriod(void)
{
	int period = MacroGhostThemeManagerMainPageDefaultRefreshPeriod;
	GhostMutexLock(&manager->Mutex);
	period = manager->MainPageRefreshPeriod;
	GhostMutexUnlock(&manager->Mutex);
	return period;
}


/// <summary>
/// Set refresh period of main page.
///		The default value of period is 500.
///		Period should be greater than return value of GhostThemeMgrGetMainPageMinimumRefreshPeriod().
///		It will be set to the minimum value if RefreshPeriod is less than minimum value.
/// </summary>
/// <param name="Milliseconds">Refresh period of main page in milliseconds.</param>
/// <returns>Actually set refresh cycle.</returns>
int GhostThemeMgrSetMainPageRefreshPeriod(int Milliseconds)
{
	if (Milliseconds < MacroGhostThemeManagerMainPageMinimumRefreshPeriod)
	{
		Milliseconds = MacroGhostThemeManagerMainPageMinimumRefreshPeriod;
	}

	GhostMutexLock(&manager->Mutex);
	manager->MainPageRefreshPeriod = Milliseconds;
	GhostMutexUnlock(&manager->Mutex);
	return Milliseconds;
}


/// <summary>
/// Set refresh period of main page.
///		**This function should only be called in theme.**
/// 
///		The default value of period is 500.
///		Period should be greater than return value of GhostThemeMgrGetMainPageMinimumRefreshPeriod().
///		It will be set to the minimum value if RefreshPeriod is less than minimum value.
/// </summary>
/// <param name="Milliseconds">Refresh period of main page in milliseconds.</param>
/// <returns>Actually set refresh cycle.</returns>
int GhostThemeSetMainPageRefreshPeriod(const char* PackageName, int Milliseconds)
{
	if (Milliseconds < MacroGhostThemeManagerMainPageMinimumRefreshPeriod)
	{
		Milliseconds = MacroGhostThemeManagerMainPageMinimumRefreshPeriod;
	}

	manager->MainPageRefreshPeriod = Milliseconds;
	return Milliseconds;
}


/// <summary>
/// Create main page.
///		This function should be called in GhostLaucher.
/// </summary>
/// <param name="MainPage">Main page handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrMainPageCreate(lv_obj_t* MainPage)
{
	GhostMutexLock(&manager->Mutex);
	GhostThemeHandle_t* MainPageThemeHandle = manager->MainPageThemeHandle;
	GhostError_t ret = GhostOK;

	ret = MainPageThemeHandle->ThemeInfo.MainPage.Create(MainPage, MainPageThemeHandle->Resources);
	if (IfGhostError(ret))
	{
		GhostLogE("Main page of theme: %s create failed.", MainPageThemeHandle->ThemeInfo.ThemeName);
	}
	else {
		MainPageThemeHandle->MainPageLoaded = true;
	}

	GhostMutexUnlock(&manager->Mutex);
	return ret;
}


/// <summary>
/// Refresh main page.
/// 	This function should be called in GhostLaucher.
/// </summary>
/// <param name="MainPage">Main page handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrMainPageRefresh(lv_obj_t* MainPage)
{
	GhostMutexLock(&manager->Mutex);
	GhostThemeHandle_t* MainPageThemeHandle = manager->MainPageThemeHandle;

	// Calculate run time.
	GhostError_t ret = GhostOK;

	if (MainPageThemeHandle->MainPageLoaded != true)
	{
		GhostMutexUnlock(&manager->Mutex);
		GhostLogE("Main page not loaded.");
		return GhostErrorThemeMgrThemeUninitialized;
	}
	else {
		ret = MainPageThemeHandle->ThemeInfo.MainPage.Refresh(MainPage, MainPageThemeHandle->Resources);
	}

	if (IfGhostError(ret))
	{
		GhostMutexUnlock(&manager->Mutex);
		// TODO: Switch to default theme.
		GhostLogE("Main page of theme: %s refresh failed, using deafult theme.", MainPageThemeHandle->ThemeInfo.ThemeName);
		return ret;
	}
	GhostMutexUnlock(&manager->Mutex);
	return GhostOK;
}



/// <summary>
/// Create AppList page.
///		This function should be called in GhostLaucher.
/// </summary>
/// <param name="AppListPage">AppList page handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrAppDrawerPageCreate(lv_obj_t* AppDrawerPage)
{
	GhostMutexLock(&manager->Mutex);
	GhostThemeHandle_t* AppDrawerPageThemeHandle = manager->AppDrawerPageThemeHandle;
	GhostError_t ret = GhostOK;

	ret = AppDrawerPageThemeHandle->ThemeInfo.AppDrawerPage.Create(AppDrawerPage, AppDrawerPageThemeHandle->Resources);
	if (IfGhostError(ret))
	{
		GhostLogE("App drawer page of theme: %s create failed.", AppDrawerPageThemeHandle->ThemeInfo.ThemeName);
	}
	else {
		AppDrawerPageThemeHandle->AppDrawerPageLoaded = true;
	}

	GhostMutexUnlock(&manager->Mutex);
	return ret;
}


/// <summary>
/// Refresh AppList page.
/// 	This function should be called in GhostLaucher.
/// </summary>
/// <param name="MainPage">Main page handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrAppDrawerPageRefresh(lv_obj_t* AppDrawerPage)
{
	GhostMutexLock(&manager->Mutex);
	GhostThemeHandle_t* AppDrawerPageThemeHandle = manager->AppDrawerPageThemeHandle;

	// Calculate run time.
	GhostError_t ret = GhostOK;

	if (AppDrawerPageThemeHandle->AppDrawerPageLoaded != true)
	{
		GhostMutexUnlock(&manager->Mutex);
		GhostLogE("Main page not loaded.");
		return GhostErrorThemeMgrThemeUninitialized;
	}
	else {
		ret = AppDrawerPageThemeHandle->ThemeInfo.MainPage.Refresh(AppDrawerPage, AppDrawerPageThemeHandle->Resources);
	}

	if (IfGhostError(ret))
	{
		GhostMutexUnlock(&manager->Mutex);
		// TODO: Switch to default theme.
		GhostLogE("App drawer page of theme: %s refresh failed, using deafult theme.", AppDrawerPageThemeHandle->ThemeInfo.ThemeName);
		return ret;
	}
	GhostMutexUnlock(&manager->Mutex);
	return GhostOK;
}


/// <summary>
/// 
/// </summary>
/// <param name="PackageName"></param>
/// <returns></returns>
MacroStatic GhostThemeHandle_t* ghostThemeFindHandleByPackageName(const char* PackageName)
{
	GhostThemeHandle_t tempHandle;
	tempHandle.ThemeInfo.PackageName = PackageName;
	list_node_t* handle = list_find(manager->Themes, &tempHandle);
	return ((GhostThemeHandle_t*)handle->val);
}


/// <summary>
/// 
/// </summary>
/// <param name="PackageName"></param>
/// <returns></returns>
MacroStatic GhostError_t setDefaultTheme(const char* PackageName)
{
	GhostThemeHandle_t* mainPageHandle = ghostThemeFindHandleByPackageName(PackageName);

	if (mainPageHandle == NULL)
	{
		return GhostErrorThemeOutOfMemory;
	}

	// Lock mutex.
	if (!mainPageHandle->ThemeLoaded)
	{
		mainPageHandle->ThemeInfo.ThemeInit();
		mainPageHandle->ThemeLoaded = true;
	}
	manager->MainPageThemeHandle = mainPageHandle;
	manager->AppDrawerPageThemeHandle = mainPageHandle;
	return GhostOK;
}

