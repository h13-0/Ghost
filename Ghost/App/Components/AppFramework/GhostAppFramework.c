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

// Standard headers.
#include <string.h>
#include <stdlib.h>

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
#include "GhostAppAPIs.h"

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
/// The linked list typedef of GhostApplicationList.
/// </summary>
typedef struct GhostAppHandle
{
	// Application message.
	GhostAppInfo_t       AppInfo;

	// Status.
	GhostAppStatus_t     AppStatus : 2;

	// Owner.
	GhostAppOwner_t      AppOwner  : 2;

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

	// 
	lv_style_t ScreenStyle;

	int NativeAppsNum;
	int LuaAppsNum;

	// Linked list.
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
static GhostAppHandle_t* ghostAppFrmAppHandleNew(const GhostAppInfo_t AppInfo);


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
static void ghostAppFrmAppHandleFree(const GhostAppInfo_t ApplicationInfo);


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
		GhostMutexInit(&framework.Mutex);
		GhostMutexLock(&framework.Mutex);

		// Now we are safe.
		// Overwrite linked-list function.
		framework.AppHandles->match = ghostAppFrmAppHandleMatch;
		framework.AppHandles->free = ghostAppFrmAppHandleFree;
		

		// Create default page style.
		lv_style_init(&framework.ScreenStyle);
		lv_style_set_border_width(&framework.ScreenStyle, 0);
		lv_style_set_pad_all(&framework.ScreenStyle, 0);
		int radius = 0;
		GhostScreenGetRadius(&radius);
		lv_style_set_radius(&framework.ScreenStyle, MacroQtDefaultFilletRadius);

		// TODO: Get application list.


		GhostMutexUnlock(&framework.Mutex);
		return GhostOK;
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
	return GhostAppStatusNotInstalled;
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
GhostAppInfo_t GhostAppFrmAppInfoNew(GhostAppType_t AppType, char* PackageName,
	char* AppName, char* IconPath, int Version,
	GhostError_t(*EntryHandle)(int Argc, void** Args),
	GhostError_t(*DestoryHandle)(int Countdown, char** TranceBackMsg))
{
	struct __ghostAppInfo info = {
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
	if (AppInfo != NULL)
	{
		if (AppInfo->PackageName != NULL)
		{
			GhostMemMgrFree(AppInfo->PackageName);
		}

		if (AppInfo->AppName != NULL)
		{
			GhostMemMgrFree(AppInfo->AppName);
		}

		if (AppInfo->IconPath != NULL)
		{
			GhostMemMgrFree(AppInfo->IconPath);
		}

		GhostMemMgrFree(AppInfo);
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
GhostAppInfo_t GhostAppFrmAppInfoClone(const GhostAppInfo_t AppInfo)
{
	// Allocate memory.
	GhostAppInfo_t info = GhostMemMgrCalloc(1, sizeof(GhostAppInfo_t));
	
	// Check allocate result.
	if (info == NULL)
	{
		GhostLogE("Clone app info failed, out of memory!");
		return NULL;
	}

	*info = *AppInfo;
	// Clone PackageName.
	//> Allocate memory.
	info->PackageName = GhostMemMgrMalloc(strlen(AppInfo->PackageName) + 1);
	info->AppName = GhostMemMgrMalloc(strlen(AppInfo->AppName) + 1);
	info->IconPath = GhostMemMgrMalloc(strlen(AppInfo->IconPath) + 1);
	
	//> Check allocate result.
	if (info->PackageName == NULL || info->AppName == NULL || info->IconPath == NULL)
	{
		GhostLogE("Clone app info failed, out of memory!");
		// Free.
		GhostAppFrmAppInfoFree(info);
		return NULL;
	}

	//> Copy string.
	memcpy(info->PackageName, AppInfo->PackageName, strlen(AppInfo->PackageName) + 1);
	memcpy(info->AppName, AppInfo->AppName, strlen(AppInfo->AppName) + 1);
	memcpy(info->IconPath, AppInfo->IconPath, strlen(AppInfo->IconPath) + 1);
	return info;
}


/// <summary>
/// Verify whether `GhostAppInfo_t` is legal.
/// Thread safety:
///		Yes.
/// </summary>
/// <returns>GhostOK if vaild.</returns>
GhostError_t GhostAppFrmVerifyAppInfo(const GhostAppInfo_t AppInfo)
{
	// TODO: Check icons.

	// Check parameters.
	//> Check AppType.
	if (AppInfo->AppType < GhostAppTypeNative || AppInfo->AppType > GhostAppTypeNum)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}

	//> Check packagename.
	if (AppInfo->PackageName == NULL)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}
	else {
		int length = strlen(AppInfo->PackageName);
		if (length == 0 || length > MacroMaximumAppPackageNameLength)
		{
			return GhostAppFrmErrAppInfoIllegal;
		}

		// TODO: Regex.
	}

	//> Check app name.
	if (AppInfo->AppName == NULL)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}
	else {
		int length = strlen(AppInfo->AppName);
		if (length == 0 || length > MacroMaximumAppNameLength)
		{
			return GhostAppFrmErrAppInfoIllegal;
		}

		// TODO: Regex.
	}

	//> Check icon path.
	if (AppInfo->AppName != NULL)
	{
		// Check file and picture.
		// TODO.
	}


	//> Check version.
	if (AppInfo->Version <= 0)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}

	//> Check entry handle.
	if (AppInfo->EntryHandle == NULL)
	{
		return GhostAppFrmErrAppInfoIllegal;
	}
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
GhostError_t GhostAppFrmRegisterApp(const GhostAppInfo_t AppInfo)
{
	GhostError_t ret = GhostOK;

	// Lock mutex.
	GhostMutexLock(framework.Mutex);
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
		switch (AppInfo->AppType)
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
	GhostMutexUnlock(framework.Mutex);
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
	GhostMutexLock(framework.Mutex);
	do {
		list_node_t* node;
		list_iterator_t* it = list_iterator_new(framework.AppHandles, LIST_HEAD);
		while ((node = list_iterator_next(it))) {
			if (!strncmp(PackageName, ((GhostAppHandle_t*)node)->AppInfo->PackageName, MacroMaximumAppPackageNameLength))
			{
				handle = (GhostAppHandle_t*)node;
				break;
			}
		}
	} while (0);

	// Unlock mutex.
	GhostMutexUnlock(framework.Mutex);
	return handle;
}


/// <summary>
/// Get appliaction info by package name.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <returns>Create failed when the return value is null.</returns>
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
GhostError_t GhostAppFrmRunForeground(const char* const PackageName, int Argc, void** Args)
{
	GhostError_t ret = GhostOK;

	// Get app handle.
	GhostAppHandle_t* handle = GhostAppFrmGetAppHandle(PackageName);
	if (handle != NULL)
	{
		// Lock mutex.
		GhostMutexLock(framework.Mutex);

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
			handle->AppStatus = GhostAppStatusForeground;
		} while (0);

		// Unlock mutex.
		GhostMutexUnlock(framework.Mutex);
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
GhostError_t GhostAppFrmRunBackground(const char* const PackageName, int Argc, void** Args)
{
	GhostError_t ret = GhostOK;

	// Get app handle.
	GhostAppHandle_t* handle = GhostAppFrmGetAppHandle(PackageName);
	if (handle != NULL)
	{
		// Lock mutex.
		GhostMutexLock(framework.Mutex);

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
		GhostMutexUnlock(framework.Mutex);
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
GhostError_t GhostAppMgrStopApp(const GhostAppInfo_t ApplicationInfo)
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
static GhostAppHandle_t* ghostAppFrmAppHandleNew(const GhostAppInfo_t AppInfo)
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


/*
/// <summary>
/// Generate application list.
///		**The `ApplicationListPtr` should be released after use!**
/// </summary>
/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrGenerateApplicationList(GhostAppList_t* const ApplicationListPtr)
{
	return GhostOK;
}


/// <summary>
/// Release application list.
/// </summary>
/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
/// <returns></returns>
GhostError_t GhostAppMgrDestoryApplicationList(GhostAppList_t* ApplicationListPtr)
{
	return GhostOK;
}
*/
