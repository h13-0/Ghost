/*******************************************************************************
 * @File   : $safeitemname$
 * @Path   : $rootnamespace$
 * @Module :
 *
 * @Author : $username$
 * @Time   : $time$
 * @license: AGPL-3.0(https://github.com/h13-0/Ghost/blob/master/LICENSE)
 * @Notes  :
 *		This template file is only applicable to visual studio.
 *
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"
// Self headers.
#include "GhostAppFramework.h"
#include "GhostAppAPIs.h"

// Standard headers.
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ThirdParty headers.
#include "list.h"

// Ghost headers.
#include "GhostSafeLVGL.h"
#include "GhostMemoryManager.h"
#include "GhostLog.h"
#include "GhostThread.h"
#include "GhostFileSystem.h"
#include "GhostScreen.h"
#include "GhostAppResourcePool.h"


/***********************************Defines************************************/



/***********************************Typedefs***********************************/
/// <summary>
/// 
/// </summary>
typedef struct GhostAppResources
{
	//
	void* ResourcePtr;

	//
	GhostError_t(*ResourceDestructor)(void*);

	// Next node.
	struct GhostAppResources* NextResourceNode;
} GhostAppResources_t;


/// <summary>
/// Typedef of AppInfo.
/// </summary>
typedef struct
{
	GhostAppType_t AppType;
	char* PackageName;
	char* AppName;
	char* IconPath;                                                     // Optional.
	int Version;
	GhostError_t(*EntryHandle)(int Argc, void** Args);
	GhostError_t(*DestoryHandle)(int Countdown, char** TranceBackMsg);  // Optional.
} AppInfo_t;


/// <summary>
/// The linked list typedef of GhostApplicationList.
/// </summary>
typedef struct GhostAppHandle
{
	// Application message.
	AppInfo_t*           AppInfo;

	// Status.
	GhostAppStatus_t     AppStatus : (GhostAppStatusNum + 1) / 2;

	// Owner.
	GhostAppOwner_t      AppOwner  : (GhostAppOwnerNum + 1) / 2;

	// Authorization.
	GhostAppAuth_t       AppAuth;

	// Resources.
	GhostAppResPool_t    ResPool;
	//> Special resources.
	
	GhostThread_t        MainThread;
	GhostVirtualScreen_t Screen;

	//TODO.

} GhostAppHandle_t;


/// <summary>
/// Typedef struct of GhostApplicationManager.
/// </summary>
typedef struct {
	// Mutex.
	GhostMutex_t Mutex;

	int NativeAppsNum;
	int LuaAppsNum;

	// Foreground app.
	GhostAppHandle_t* ForegroundApp;

	// Virtual screen varibles.
	lv_style_t ScreenStyle;
	int ScreenWidth;
	int ScreenHeight;
	int ScreenRadius;

	// App handles and address offset.
#if(MacroGhostAppFrmUseTokenOffset)
	size_t  AppTokenOffset;
#endif
	list_t* AppHandles; // App handles in GhostAppHandle_t.
} GhostAppFrm_t;




/**********************************Prototypes**********************************/
static GhostAppFrm_t framework = { 0 };

// Static functions.
/// <summary>
/// Create `GhostAppHandle_t` by AppInfo.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="AppInfo">App info in pointor of `GhostAppInfo_t`.</param>
/// <returns>
/// Pointor of GhostAppHandle_t.
///		Create failed when the return value is null.
/// </returns>
static GhostAppHandle_t* ghostAppFrmAppHandleNew(GhostAppInfo_t AppInfo);


/// <summary>
/// Compare whether the GhostAppHandle_t are the same by package name.
/// This function does not check whether AppInfo is legal, and is not responsible for the input.
/// </summary>
/// <param name="HandleA">App handle.</param>
/// <param name="HandleB">App handle.</param>
/// <returns>Return 1 when the package name is the same.</returns>
static int ghostAppFrmAppHandleMatch(const GhostAppHandle_t* HandleA, const GhostAppHandle_t* HandleB);


/// <summary>
/// Free memory of `GhostAppHandle_t`.
/// </summary>
/// <param name="Handle">App handle.</param>
static void ghostAppFrmAppHandleFree(GhostAppInfo_t ApplicationInfo);


/// <summary>
/// Get App handle by app token.
/// </summary>
/// <param name="AppToken">AppToken in GhostAppArgs_t.</param>
/// <returns>App handle.</returns>
static inline GhostAppHandle_t* ghostAppFrmGetAppHandleByToken(GhostAppToken_t AppToken, bool Locked);


/// <summary>
/// Get App token by app handle.
/// </summary>
/// <param name="AppHandle">App handle.</param>
/// <returns>App handle.</returns>
static inline GhostAppToken_t ghostAppFrmGetAppTokenByHandle(GhostAppHandle_t* AppHandle, bool Locked);


/// <summary>
/// Init Ghost application framework.
/// Thread safety:
///		Unsafe first run.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmInit(void)
{
	if (framework.AppHandles == NULL)
	{
		// Not inited.
		// Init linked list.
		framework.AppHandles = list_new();

		// Init mutex.
		GhostTerminateIfErr(GhostMutexInit(&framework.Mutex));
		GhostTerminateIfErr(GhostMutexLock(&framework.Mutex));

		GhostError_t ret = GhostOK;

		do {
			// Now we are safe.
			// Overwrite linked-list function.
			framework.AppHandles->match = ghostAppFrmAppHandleMatch;
			framework.AppHandles->free = ghostAppFrmAppHandleFree;


			// Create default page style.
			lv_style_init(&framework.ScreenStyle);
			lv_style_set_border_width(&framework.ScreenStyle, 0);
			lv_style_set_pad_all(&framework.ScreenStyle, 0);

			// Get Screen info.
			framework.ScreenWidth = GhostScreenGetWidth();
			framework.ScreenHeight = GhostScreenGetHeight();
			framework.ScreenRadius = GhostScreenGetRadius();
			lv_style_set_radius(&framework.ScreenStyle, MacroQtDefaultFilletRadius);

			// TODO: Get application list.

			// Generate random token offset.
			framework.AppTokenOffset = rand();
		} while (0);

		// Unlock.
		GhostMutexUnlock(&framework.Mutex);
		return ret;
	}
	else {
		// Inited.
		GhostLogE("App framework repeated inited.");
		return GhostAppFrmErrRepeatedInited;
	}

	return GhostOK;
}


/// <summary>
/// Query app status using package name.
/// Thread safety:
///		Yes.
/// </summary>
/// <returns>Ghost app status in GhostAppStatus_t.</returns>
GhostAppStatus_t GhostAppFrmGetAppStatus(const char* PackageName)
{
	// TODO.
	// GhostMutexLock
	return GhostAppStatusNotFound;
}


/// <summary>
/// Create new AppInfo_t by info.
/// </summary>
/// <param name="AppType">Type of Ghost app type.</param>
/// <param name="PackageName">Package name.</param>
/// <param name="IconPath">[Optional] Icon path, If NULL, use the default icon.</param>
/// <param name="Version">Version ID, greater than 0.</param>
/// <param name="EntryHandle">Entry handle of app.</param>
/// <param name="DestoryHandle">
/// [Optional] Active destroy handle, will be called 200ms brefore the app has killed. 
/// If NULL, app will be killed immediately.
/// </param>
/// <returns> Create failed when the return value is null. </returns>
GhostAppInfo_t GhostAppInfoNew(GhostAppType_t AppType, char* PackageName,
	char* AppName, char* IconPath, int Version,
	GhostError_t(*EntryHandle)(int Argc, void** Args),
	GhostError_t(*DestoryHandle)(int Countdown, char** TranceBackMsg))
{
	AppInfo_t info = {
		.AppType = AppType,
		.PackageName = PackageName,
		.AppName = AppName,
		.IconPath = IconPath,
		.Version = Version,
		.EntryHandle = EntryHandle,
		.DestoryHandle = DestoryHandle
	};

	if (IfGhostError(GhostAppFrmVerifyAppInfo(&info)))
	{
		return NULL;
	}
	else {
		GhostAppInfo_t new_info = GhostAppFrmAppInfoClone(&info);
		return new_info;
	}
}


/// <summary>
/// Free memory of `GhostAppInfo_t`.
/// </summary>
/// <param name="AppInfo">App info in pointor of `GhostAppInfo_t`.</param>
void GhostAppFrmAppInfoFree(const GhostAppInfo_t AppInfo)
{
	AppInfo_t* appInfo = AppInfo;
	if (appInfo != NULL)
	{
		if (appInfo->PackageName != NULL)
		{
			GhostMemMgrFree(appInfo->PackageName);
		}

		if (appInfo->AppName != NULL)
		{
			GhostMemMgrFree(appInfo->AppName);
		}

		if (appInfo->IconPath != NULL)
		{
			GhostMemMgrFree(appInfo->IconPath);
		}

		GhostMemMgrFree(appInfo);
	}
}


/// <summary>
/// Clone `AppInfo` to a new `GhostAppInfo_t`.
/// This function will not verify info.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="AppInfo">App info in pointor of `GhostAppInfo_t`.</param>
/// <returns> Create failed when the return value is null. </returns>
GhostAppInfo_t GhostAppFrmAppInfoClone(GhostAppInfo_t AppInfo)
{
	AppInfo_t* appInfo = AppInfo;
	// Allocate memory.
	AppInfo_t* info = GhostMemMgrCalloc(1, sizeof(AppInfo_t));
	
	// Check allocate result.
	if (info == NULL)
	{
		GhostLogE("Clone app info failed, out of memory!");
		return NULL;
	}

	*info = *appInfo;
	// Clone PackageName.
	//> Allocate memory.
	info->PackageName = GhostMemMgrMalloc(strlen(appInfo->PackageName) + 1);
	info->AppName = GhostMemMgrMalloc(strlen(appInfo->AppName) + 1);
	if (info->IconPath != NULL)
	{
		info->IconPath = GhostMemMgrMalloc(strlen(appInfo->IconPath) + 1);
	}
	
	//> Check allocate result.
	if (info->PackageName == NULL || info->AppName == NULL || (appInfo->IconPath != NULL && info->IconPath == NULL))
	{
		GhostLogE("Clone app info failed, out of memory!");
		// Free.
		GhostAppFrmAppInfoFree(info);
		return NULL;
	}

	//> Copy string.
	memcpy(info->PackageName, appInfo->PackageName, strlen(appInfo->PackageName) + 1);
	memcpy(info->AppName, appInfo->AppName, strlen(appInfo->AppName) + 1);
	if (info->IconPath != NULL)
	{
		memcpy(info->IconPath, appInfo->IconPath, strlen(appInfo->IconPath) + 1);
	}
	
	return info;
}


/// <summary>
/// Verify whether `GhostAppInfo_t` is legal.
/// Thread safety:
///		Yes.
/// </summary>
/// <returns>GhostOK if vaild.</returns>
GhostError_t GhostAppFrmVerifyAppInfo(GhostAppInfo_t AppInfo)
{
	AppInfo_t* appInfo = AppInfo;
	// TODO: Check icons.

	// Check parameters.
	//> Check AppType.
	if (appInfo->AppType < GhostAppTypeNative || appInfo->AppType > GhostAppTypeNum)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}

	//> Check packagename.
	if (appInfo->PackageName == NULL)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}
	else {
		int length = strlen(appInfo->PackageName);
		if (length == 0 || length > MacroMaximumAppPackageNameLength)
		{
			return GhostAppFrmErrAppInfoIllegal;
		}

		// TODO: Regex.
	}

	//> Check app name.
	if (appInfo->AppName == NULL)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}
	else {
		int length = strlen(appInfo->AppName);
		if (length == 0 || length > MacroMaximumAppNameLength)
		{
			return GhostAppFrmErrAppInfoIllegal;
		}

		// TODO: Regex.
	}

	//> Check icon path.
	if (appInfo->AppName != NULL)
	{
		// Check file and picture.
		// TODO.
	}


	//> Check version.
	if (appInfo->Version < 0)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}

	//> Check entry handle.
	if (appInfo->EntryHandle == NULL)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}
	return GhostOK;
}


/// <summary>
/// Register an app to the app list.
/// Thread safety:
///		Yes.
/// </summary>
/// <workflow>
/// ParamCheck -> MakeAppHandle -> 
/// 
/// </workflow>
/// <param name="AppInfo">Application info.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmRegisterApp(GhostAppInfo_t AppInfo)
{
	AppInfo_t* appInfo = AppInfo;
	GhostError_t ret = GhostOK;

	// Lock mutex.
	GhostMutexLock(&framework.Mutex);
	do {
		// Verify whether AppInfo is legal.
		if (IfGhostError(ret = GhostAppFrmVerifyAppInfo(AppInfo)))
		{
			break;
		}

		// Make sure the package name is unique.
		GhostAppHandle_t* handle = ghostAppFrmAppHandleNew(AppInfo);
		if (handle == NULL)
		{
			GhostLogE("GhostAppFrmRegister failed, out of memory!");
			ret = GhostAppFrmErrOutOfMemory;
			break;
		}

		// Push to linked-list.
		if (!list_find(framework.AppHandles, handle))
		{
			// Push
			list_rpush(framework.AppHandles, list_node_new(handle));
		}
		else {
			// Duplicate packagename.
			GhostLogE("GhostAppFrmRegister failed, Duplicate PackageName.");
			ret = GhostAppFrmErrDuplicatePackageName;
			break;
		}

		// App count.
		switch (appInfo->AppType)
		{
		case GhostAppTypeNative:
			framework.NativeAppsNum++;
			break;

		case GhostAppTypeLua:
			framework.LuaAppsNum++;
			break;

		default:
			break;
		}
	} while (0);
	
	// Unlock mutex.
	GhostMutexUnlock(&framework.Mutex);
	return ret;
}


/// <summary>
/// Get pointor of application handle in Ghost App Framework.
/// This method is a DAGEROUS operation and only allowed for Ghost system.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="PackageName"></param>
/// <returns>Returns NULL when the app does not exist.</returns>
void* GhostAppFrmGetAppHandle(const char* PackageName)
{
	void* handle = NULL;

	// Check parameters.
	if (PackageName == NULL || strlen(PackageName) == 0)
	{
		return NULL;
	}

	// Lock mutex.
	GhostMutexLock(&framework.Mutex);
	do {
		list_node_t* node;
		list_iterator_t* it = list_iterator_new(framework.AppHandles, LIST_HEAD);
		while ((node = list_iterator_next(it))) {
			if (!strncmp(PackageName, ((GhostAppHandle_t*)node->val)->AppInfo->PackageName, MacroMaximumAppPackageNameLength))
			{
				handle = (GhostAppHandle_t*)node->val;
				break;
			}
		}
	} while (0);

	// Unlock mutex.
	GhostMutexUnlock(&framework.Mutex);
	return handle;
}


/// <summary>
/// Get appliaction info by package name.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <returns>
/// Returns NULL when the app does not exist or out of memory.
/// </returns>
GhostAppInfo_t GhostAppFrmGetAppInfo(const char* PackageName)
{
	GhostAppHandle_t* handle = GhostAppFrmGetAppHandle(PackageName);
	if (handle != NULL)
	{
		return GhostAppFrmAppInfoClone(handle->AppInfo);
	}
	else {
		return NULL;
	}
}


/// <summary>
/// Run an app in foreground.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmRunForeground(const char* PackageName, int Argc, char** Argv)
{
	GhostError_t ret = GhostOK;

	// Get app handle.
	GhostAppHandle_t* handle = GhostAppFrmGetAppHandle(PackageName);
	if (handle != NULL)
	{
		// Lock mutex.
		GhostMutexLock(&framework.Mutex);

		do {
			if (handle->AppStatus == GhostAppStatusForeground)
			{
				break;
			}
			else if (handle->AppStatus == GhostAppStatusBackground)
			{
				// TODO.
				break;
			}
			else {
				handle->ResPool = GhostAppResPoolNew(MacroGhostAppDefaultResPoolCapacity);
				GhostAppArgs_t* args = GhostMemMgrCalloc(1, sizeof(GhostAppArgs_t));
				if (args == NULL)
				{
					ret = GhostAppFrmErrOutOfMemory;
					break;
				}
				
				// Clone argv.
				args->Argv = GhostMemMgrCalloc(1, ((strlen(Argv)) + 1) * sizeof(char));
				if (args->Argv == NULL)
				{
					ret = GhostAppFrmErrOutOfMemory;
					GhostMemMgrFree(args);
					break;
				}
				
				args->AppToken = ghostAppFrmGetAppTokenByHandle(handle, true);

				// Clone argv.
				memcpy(args->Argv, Argv, ((strlen(Argv)) + 1) * sizeof(char));

				// Add to AppResPool.
				GhostAppResPoolAddItem(handle->ResPool, args, GhostMemMgrFree);
				GhostAppResPoolAddItem(handle->ResPool, args->Argv, GhostMemMgrFree);

				if (IfGhostError(
						GhostThreadCreate(
							//handle->AppInfo.
							&handle->MainThread,
							handle->AppInfo->EntryHandle,
							handle->AppInfo->PackageName,
							0,
							args,
							1
						))
					)
				{
					// If error:
					ret = GhostAppFrmErrCreateThreadError;
					// TODO: free memory.
					break;
				}
				
				framework.ForegroundApp = handle;
			}
			handle->AppStatus = GhostAppStatusForeground;
		} while (0);

		// Unlock mutex.
		GhostMutexUnlock(&framework.Mutex);
	}
	else {
		GhostLogE("Ghost App run failed, App: %s not found.", PackageName);
		return GhostAppFrmErrAppNotFound;
	}

	return GhostOK;
}


/// <summary>
/// Run an app in background.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmRunBackground(const char* PackageName, int Argc, void** Args)
{
	GhostError_t ret = GhostOK;

	// Get app handle.
	GhostAppHandle_t* handle = GhostAppFrmGetAppHandle(PackageName);
	if (handle != NULL)
	{
		// Lock mutex.
		GhostMutexLock(&framework.Mutex);

		do {
			if (handle->AppStatus == GhostAppStatusBackground)
			{
				break;
			}
			else if (handle->AppStatus == GhostAppStatusForeground)
			{
				// TODO.
				break;
			}
			else {
				// Create args.
				// TODO
				// + manager.offset

				if (IfGhostError(
					GhostThreadCreate(
						//handle->AppInfo.
						&handle->MainThread,
						handle->AppInfo->EntryHandle,
						handle->AppInfo->PackageName,
						0,
						handle,
						1
					))
					)
				{
					// If error:
					ret = GhostAppFrmErrCreateThreadError;
					break;
				}
			}
			handle->AppStatus = GhostAppStatusBackground;
		} while (0);

		// Unlock mutex.
		GhostMutexUnlock(&framework.Mutex);
	}
	else {
		GhostLogE("Ghost App run failed, App: %s not found.", PackageName);
		return GhostAppFrmErrAppNotFound;
	}

	return GhostOK;
}


/// <summary>
/// Stop app by appliaction info.
/// </summary>
/// <param name="ApplicationInfo"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrStopApp(GhostAppInfo_t ApplicationInfo)
{
	GhostError_t ret = GhostOK;
	// Wait for UI to idle.
	GhostLogIfError(Warning, GhostLV_Lock());
	// 

	GhostLogIfError(Warning, GhostLV_Unlock());

	return GhostOK;
}


/// <summary>
/// Uninstall an app.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrUninstall(const char* PackageName)
{

	// Delete files.
	// TODO:

	return GhostOK;
}

// static functions.

/// <summary>
/// Create `GhostAppHandle_t` by AppInfo.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="AppInfo">App info in pointor of `GhostAppInfo_t`.</param>
/// <returns>
/// Pointor of GhostAppHandle_t.
///		Create failed when the return value is null.
/// </returns>
static GhostAppHandle_t* ghostAppFrmAppHandleNew(GhostAppInfo_t AppInfo)
{
	if (IfGhostError(GhostAppFrmVerifyAppInfo(AppInfo)))
	{
		return NULL;
	}
	else {
		GhostAppHandle_t* handle = GhostMemMgrCalloc(1, sizeof(GhostAppHandle_t));
		if (handle == NULL)
		{
			GhostLogE("Make app handle failed, out of memory!");
			return NULL;
		}

		// Clone AppInfo.
		handle->AppInfo = GhostAppFrmAppInfoClone(AppInfo);
		if (handle->AppInfo == NULL)
		{
			GhostLogE("Make app handle failed, out of memory!");
			GhostMemMgrFree(handle);
			return NULL;
		}

		return handle;
	}
}


/// <summary>
/// Compare whether the GhostAppHandle_t are the same by package name.
/// This function does not check whether AppInfo is legal, and is not responsible for the input.
/// </summary>
/// <param name="HandleA">App handle.</param>
/// <param name="HandleB">App handle.</param>
/// <returns>Return 1 when the package name is the same.</returns>
static int ghostAppFrmAppHandleMatch(const GhostAppHandle_t* HandleA, const GhostAppHandle_t* HandleB)
{
	// Simple check.
	if ((HandleA == NULL) || (HandleB == NULL) ||
		(HandleA->AppInfo->PackageName == NULL) ||
		(HandleB->AppInfo->PackageName == NULL))
	{
		return 0;
	}

	if (!strcmp(HandleA->AppInfo->PackageName, HandleB->AppInfo->PackageName))
	{
		return 1;
	}
	else {
		return 0;
	}
}


/// <summary>
/// Free memory of `GhostAppHandle_t`.
/// </summary>
/// <param name="Handle">App handle.</param>
static void ghostAppFrmAppHandleFree(const GhostAppHandle_t* Handle)
{
	if (Handle != NULL)
	{
		if (Handle->AppInfo != NULL)
		{
			GhostAppFrmAppInfoFree(Handle->AppInfo);
		}

		GhostMemMgrFree(Handle);
	}
}


/// <summary>
/// Get App handle by app token.
/// </summary>
/// <param name="AppToken">AppToken in GhostAppArgs_t.</param>
/// <returns>App handle.</returns>
GhostAppHandle_t* ghostAppFrmGetAppHandleByToken(GhostAppToken_t AppToken, bool Locked)
{
#if(MacroGhostAppFrmUseTokenOffset)
	GhostAppHandle_t* handle = NULL;

	if (!Locked)
	{
		GhostMutexLock(&framework.Mutex);
	}

	handle = (GhostAppHandle_t*)((size_t)AppToken - (size_t)framework.AppTokenOffset);

	if (!Locked)
	{
		GhostMutexUnlock(&framework.Mutex);
	}

	return handle;
#else
	return AppToken;
#endif // MacroGhostAppFrmUseTokenOffset
}


/// <summary>
/// Get App token by app handle.
/// </summary>
/// <param name="AppHandle">App handle.</param>
/// <returns>App handle.</returns>
static inline GhostAppToken_t ghostAppFrmGetAppTokenByHandle(GhostAppHandle_t* AppHandle, bool Locked)
{
#if(MacroGhostAppFrmUseTokenOffset)
	GhostAppToken_t token = NULL;

	if (!Locked)
	{
		GhostMutexLock(&framework.Mutex);
	}

	token = (GhostAppToken_t*)((size_t)AppHandle + (size_t)framework.AppTokenOffset);

	if (!Locked)
	{
		GhostMutexUnlock(&framework.Mutex);
	}

	return token;
#else
	return AppHandle;
#endif // MacroGhostAppFrmUseTokenOffset
}


/// <summary>
/// App exec handle.
/// According to the specification, this api should be called in the main App thread.
/// The app cannot display the UI and the app status is `GhostAppStatusLoading` 
///		until this function is called.
/// </summary>
/// <param name="AppToken">AppToken in GhostAppArgs_t.</param>
/// <returns>
/// Reason for program exit.
/// </returns>
GhostError_t GhostAppExec(GhostAppToken_t AppToken)
{
	// Enable screen.
	// TODO.
	GhostAppHandle_t* app = NULL;
	GhostAppHandle_t* foregroundApp = NULL;

	// Lock 
	GhostMutexLock(&framework.Mutex);

	// Get AppHandle by AppToken.
	app = ghostAppFrmGetAppHandleByToken(AppToken, true);
	foregroundApp = framework.ForegroundApp;

	// Set virtual screen visible.
	if (foregroundApp == app && app->Screen != NULL)
	{
		if (app->Screen != NULL)
		{
			// TODO: Lock lvgl.
			lv_obj_clear_flag(app->Screen, LV_OBJ_FLAG_HIDDEN);
		}
		else
		{
			// TODO: Mask as Non-UI App.

		}
	}

	// Unlock.
	GhostMutexUnlock(&framework.Mutex);


	while (1)
	{
		GhostSleepMillisecond(1000);
	}
}


/// <summary>
/// Get virtual screen by AppToken.
/// </summary>
/// <param name="AppToken">AppToken in GhostAppArgs_t.</param>
/// <param name="BackgroundColor">Background color.</param>
/// <returns>
/// Pointer of virtual screen(It's actually a lv_obj_t*).
/// </returns>
lv_obj_t* GhostAppGetVirtualScreen(GhostAppToken_t AppToken, lv_color_t BackgroundColor)
{
	lv_obj_t* screen = NULL;

	// Lock 
	GhostMutexLock(&framework.Mutex);

	do {
		GhostAppHandle_t* app = ghostAppFrmGetAppHandleByToken(AppToken, true);
		if (app->Screen != NULL)
		{
			screen = app->Screen;
			break;
		}
		else {
			GhostLV_Lock();
			app->Screen = lv_obj_create(lv_scr_act());
			if (app->Screen == NULL)
			{
				GhostLV_Unlock();
				GhostLogE("Create virtual screen failed, out of memory!");
				break;
			}
			else
			{
				screen = app->Screen;
				lv_obj_add_flag(screen, LV_OBJ_FLAG_HIDDEN);
				lv_obj_add_style(screen, &framework.ScreenStyle, 0);
				lv_obj_set_scrollbar_mode(screen, LV_SCROLLBAR_MODE_OFF);
				lv_obj_set_pos(screen, 0, 0);
				lv_obj_set_size(screen, framework.ScreenWidth, framework.ScreenHeight);
				lv_obj_set_style_bg_color(screen, BackgroundColor, 0);
				GhostLV_Unlock();
			}
		}
	} while (0);

	// Unlock.
	GhostMutexUnlock(&framework.Mutex);

	return screen;
}
