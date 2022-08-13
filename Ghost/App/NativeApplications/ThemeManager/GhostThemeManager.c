#include "GhostThemeManager.h"
#include "GhostPlatformConfigs.h"

// Standard libs.
#include <stddef.h>

// ThirdPartys.
#include "list.h"

// Drivers.
#include "GhostMemoryManager.h"
#include "GhostLog.h"
#include "GhostThread.h"

// Application manager.
#include "GhostApplicationManager.h"
#include "GhostPlatformConfigs.h"

// Built-in themes.
#include "GhostTheme.h"
#include "GhostAppleInfograph.h"


DeclareNativeAppInfo();


/// <summary>
/// Theme loaded flag enum.
/// </summary>
typedef enum
{
	NotLoaded = 0,
	Loaded    = 1,
} ThemeStatus_t;


/// <summary>
/// Typedef struct of GhostThemeHandle.
/// </summary>
typedef struct
{
	// Basic theme info.
	GhostTheme_t* ThemeInfo;

	// Resources.
	void* Resources;
	void** Blocks;



	// Theme status.
	unsigned int ThemeStatus : 1;
	
	// Page status.
	unsigned int MainPageStatus : 1 ;



} GhostThemeHandle_t;


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

	// Theme manager status.
	ThemeStatus_t ThemeManagerStatus : 1;
} GhostThemeManager_t;


// Pointor of GhostThemeManager_t.
static GhostThemeManager_t* manager = NULL;


/// <summary>
/// Register built-in themes.
///		This function will be called automatically after the initialization of the manager is completed.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
static GhostError_t ghostBuiltInThemeRegister(void)
{
	// Apple info graph(tech.h13.ghost.theme.appleinfograph)
#if defined(MacroGhostThemeAppleInfograph)
	GhostTheme_t appleInfograph = { 0 };
	appleInfograph.ThemeName = MacroGhostThemeAppleInfographName;
	appleInfograph.PackageName = MacroGhostThemeAppleInfograph;
	appleInfograph.Version = MacroGhostThemeAppleInfographVersion;
	appleInfograph.ThemeInit = MacroGhostThemeAppleInfographInitFunction;
	appleInfograph.ThemeDestory = MacroGhostThemeAppleInfographDestoryFunction;
	appleInfograph.MainPageCreate = MacroGhostThemeAppleInfographMainPageCreateFunction;
	appleInfograph.MainPageRefresh = MacroGhostThemeAppleInfographMainPageRefreshFunction;
	GhostLogTerminateIfErr(Fatal, GhostThemeMgrRegeisterBuiltInTheme(&appleInfograph));
#endif

	// Other themes...


}


/// <summary>
/// Free memory of GhostThemeHandle_t.
/// 	Thread safe:
///			Yes.
/// </summary>
/// <param name="ThemeHandle">Theme handle.</param>
static void ghostThemeHandleDestory(GhostThemeHandle_t* ThemeHandle)
{
	GhostMemMgrFree(ThemeHandle->ThemeInfo->PackageName);
	GhostMemMgrFree(ThemeHandle->ThemeInfo->ThemeName);
}


/// <summary>
/// Compare whether the theme handle are the same by package name.
/// </summary>
/// <param name="ThemeHandleA">Theme handle.</param>
/// <param name="ThemeHandleB">Theme handle.</param>
/// <returns>Return 1 when the package name is the same.</returns>
static int ghostThemeHandleMatch(GhostThemeHandle_t* ThemeHandleA, GhostThemeHandle_t* ThemeHandleB)
{
	// Easy check.
	if (ThemeHandleA == ThemeHandleB)
	{
		return 1;
	}

	if ((ThemeHandleA == NULL) || (ThemeHandleB == NULL))
	{
		return 0;
	}

	// Check strlen.
	int packageNameLenOfA = strlen(ThemeHandleA->ThemeInfo->PackageName);
	int packageNameLenOfB = strlen(ThemeHandleB->ThemeInfo->PackageName);

	if (packageNameLenOfA != packageNameLenOfB)
	{
		return 0;
	}

	if (!memcmp(ThemeHandleA->ThemeInfo->PackageName, ThemeHandleB->ThemeInfo->PackageName, packageNameLenOfA))
	{
		return 1;
	}
	else {
		return 0;
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="PackageName"></param>
/// <returns></returns>
static GhostThemeHandle_t* ghostThemeFindHandleByPackageName(const char* PackageName)
{
	GhostThemeHandle_t tempHandle;
	GhostTheme_t themeInfo;
	themeInfo.PackageName = PackageName;
	tempHandle.ThemeInfo = &themeInfo;
	list_node_t* handle = list_find(manager->Themes, &tempHandle);
	return ((GhostThemeHandle_t*)handle->val);
}


/// <summary>
/// 
/// </summary>
/// <param name="PackageName"></param>
/// <returns></returns>
static GhostError_t setDefaultTheme(const char* PackageName)
{
	GhostThemeHandle_t* mainPageHandle = ghostThemeFindHandleByPackageName(PackageName);

	if (mainPageHandle == NULL)
	{
		return GhostErrorThemeOutOfMemory;
	}

	// Lock mutex.
	if (mainPageHandle->ThemeStatus != Loaded)
	{
		mainPageHandle->ThemeInfo->ThemeInit();
		mainPageHandle->ThemeStatus = Loaded;
	}
	manager->MainPageThemeHandle = mainPageHandle;
	return GhostOK;
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
	manager->Themes->match = ghostThemeHandleMatch;
	manager->Themes->free = ghostThemeHandleDestory;

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
/// Generate GhostThemeHandle_t using theme info(GhostTheme_t).
/// 	Thread safe:
///			Yes.
/// </summary>
/// <param name="ThemeInfo">Theme info in pointor of GhostTheme_t.</param>
/// <returns>
/// Pointor of theme handle.
///		Make fails when the return value is null.
/// </returns>
static GhostThemeHandle_t* ghostThemeMgrMakeThemeHandle(GhostTheme_t* ThemeInfo)
{
	GhostThemeHandle_t* handle = GhostMemMgrCalloc(1, sizeof(GhostThemeHandle_t));
	if (handle == NULL)
	{
		GhostLogE("Make theme handle failed, out of memory!");
		return NULL;
	}

	handle->ThemeInfo = GhostMemMgrMalloc(sizeof(GhostTheme_t));
	if (handle->ThemeInfo == NULL)
	{
		GhostLogE("Make theme handle failed, out of memory!");
		return NULL;
	}

	memcpy(handle->ThemeInfo, ThemeInfo, sizeof(GhostTheme_t));

	// Make a copy.
	/// Copy PackageName.
	int bufferSize = strlen(ThemeInfo->PackageName) + 1;
	handle->ThemeInfo->PackageName = GhostMemMgrMalloc(bufferSize);
	if (handle->ThemeInfo->PackageName == NULL)
	{
		GhostMemMgrFree(handle);
		GhostLogE("Make theme handle failed, out of memory!");
		return NULL;
	}
	
	memcpy(handle->ThemeInfo->PackageName, ThemeInfo->PackageName, bufferSize);

	/// Copy ThemeName.
	bufferSize = strlen(ThemeInfo->ThemeName) + 1;
	handle->ThemeInfo->ThemeName = GhostMemMgrMalloc(bufferSize);
	if (handle->ThemeInfo->ThemeName == NULL)
	{
		GhostMemMgrFree(handle->ThemeInfo->PackageName);
		GhostMemMgrFree(handle);
		GhostLogE("Make theme handle failed, out of memory!");
		return NULL;
	}

	memcpy(handle->ThemeInfo->ThemeName, ThemeInfo->ThemeName, bufferSize);
	return handle;
}


/// <summary>
/// Register built-in theme.
/// </summary>
/// <param name="Theme">Theme handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrRegeisterBuiltInTheme(GhostTheme_t* ThemeInfo)
{
	// Make theme handle.
	GhostThemeHandle_t* handle = ghostThemeMgrMakeThemeHandle(ThemeInfo);
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
	if (MainPageThemeHandle->MainPageStatus != Loaded)
	{
		if (MainPageThemeHandle->ThemeInfo->MainPageCreate != NULL)
		{
			ret = MainPageThemeHandle->ThemeInfo->MainPageCreate(MainPage, MainPageThemeHandle->Resources);
		}
		else {
			ret = GhostErrorThemeMgrNoThemeSelected;
		}
	}
	else {
		// TODO: Destory original theme.
	}

	if (IfGhostError(ret))
	{
		// TODO: Switch to default theme.
		GhostLogE("Main page of theme: %s create failed, using deafult theme.", MainPageThemeHandle->ThemeInfo->ThemeName);
	}
	else {
		MainPageThemeHandle->MainPageStatus = Loaded;
	}

	GhostMutexUnlock(&manager->Mutex);
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

	if (MainPageThemeHandle->MainPageStatus != Loaded)
	{
		GhostMutexUnlock(&manager->Mutex);
		GhostLogE("Main page not loaded.");
		return GhostErrorThemeMgrThemeUninitialized;
	}
	else {
		if (MainPageThemeHandle->ThemeInfo->MainPageRefresh != NULL)
		{
			ret = MainPageThemeHandle->ThemeInfo->MainPageRefresh(MainPage, MainPageThemeHandle->Resources);
		}
		else {
			ret = GhostErrorThemeMgrNoThemeSelected;
		}
	}


	if (IfGhostError(ret))
	{
		GhostMutexUnlock(&manager->Mutex);
		// TODO: Switch to default theme.
		GhostLogE("Main page of theme: %s refresh failed, using deafult theme.", MainPageThemeHandle->ThemeInfo->ThemeName);
		return GhostErrorThemeMgrRefreshFailed;

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
GhostError_t GhostThemeMgrAppListPageCreate(lv_obj_t* AppListPage)
{




	return GhostOK;
}


/// <summary>
/// Refresh AppList page.
/// 	This function should be called in GhostLaucher.
/// </summary>
/// <param name="MainPage">Main page handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeMgrAppListPageRefresh(lv_obj_t* AppListPage)
{
	return GhostOK;
}
