﻿#include "GhostApplicationManager.h"
#include "GhostPlatformConfigs.h"

// Standard libraries.
#include <string.h>
#include <stdlib.h>

#include "GhostSafeLVGL.h"

// Ghost drivers.
#include "GhostMemoryManager.h"
#include "GhostLog.h"
#include "GhostThread.h"
#include "GhostFileSystem.h"
#include "GhostScreen.h"

/// <summary>
/// 
/// </summary>
typedef enum
{
	GhostAppNotRunning = 0,
	GhostAppRunningForeground = 1,
	GhostAppRunningBackground = 2,
} GhostAppRunningStatus_t;


/// <summary>
/// 
/// </summary>
typedef enum
{
	GhostAppPermissionsNormalUser = 0,
	GhostAppPermissionsNativeApplication = 1,
	GhostAppPermissionsRoot = 2,
} GhostAppPermission_t;


/// <summary>
/// 
/// </summary>
typedef struct GhostAppStatus
{
	GhostAppRunningStatus_t RunningStatus : 2;
	GhostAppPermission_t Permission : 2;
	int HaveVirtualScreen : 1;
} GhostAppStatus_t;


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
typedef struct GhostAppHandleList
{
	// Application message.
	GhostAppInfo_t CurrentApplicationInfo;

	// Status.
	GhostAppStatus_t GhostAppStatus;

	// Thread.
	GhostThread_t ThreadHandle;

	// Virtual screen.
	lv_obj_t** VirtualScreen;

	// Resources.
	GhostAppResources_t* ResourceList;
	GhostAppResources_t** NextResourceNode;
	
	// Next node.
	struct GhostAppHandleList* NextApplicatonNode;
} GhostAppHandleList_t;


/// <summary>
/// Static variables of Application Manager.
///		TODO: Using external struct to save static variables.
///		TODO: Mutex.
/// </summary>
static lv_style_t screenStyle;
static GhostAppHandleList_t* applicationList = NULL;
static GhostAppHandleList_t** nextApplicatonNode = NULL;

static int nativeApplicationNumbers = 0;
static int luaApplicationNumbers = 0;

/// <summary>
/// Init Ghost application manager.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrInit(void)
{
	// TODO: Normalize the following operations.
	if (nativeApplicationNumbers == 0)
	{
		// Register Ghost System.
		GhostAppInfo_t ghostSystem = MacroGhostSystemInfo;
		GhostAppMgrRegister(&ghostSystem);
	}

	// Create default page style.
	lv_style_init(&screenStyle);
	lv_style_set_border_width(&screenStyle, 0);
	lv_style_set_pad_all(&screenStyle, 0);
	int radius;
	GhostScreenGetRadius(&radius);
	lv_style_set_radius(&screenStyle, MacroQtDefaultFilletRadius);
	
	return GhostOK;
}

/// <summary>
/// Free memory of GhostAppInfo_t.
/// </summary>
/// <param name="ApplicationInfo">Pointor of GhostAppInfo_t.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrAppInfoDestory(const GhostAppInfo_t* ApplicationInfo)
{
	if (ApplicationInfo->PackageName != NULL)
	{
		GhostMemMgrFree(ApplicationInfo->PackageName);
	}

	if (ApplicationInfo->ApplicationName != NULL)
	{
		GhostMemMgrFree(ApplicationInfo->ApplicationName);
	}

	return GhostOK;
}


/// <summary>
/// Register an app to the app list.
/// </summary>
/// <param name="ApplicationInfo">Application info.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrRegister(const GhostAppInfo_t* ApplicationInfo)
{
	// TODO: Check icons.

	// Check parameters.
	// Make sure the package name is unique.
	const GhostAppHandleList_t* ptr = applicationList;
	while (ptr != NULL)
	{
		if (!strncmp(ptr->CurrentApplicationInfo.PackageName, ApplicationInfo->PackageName, strlen(ApplicationInfo->PackageName)))
		{
			return GhostErrorAppDuplicatePackageName;
		}
		else {
			ptr = ptr->NextApplicatonNode;
		}
	}

	// Check application type.
	switch (ApplicationInfo->ApplicationType)
	{
	case GhostNativeApplication:
		nativeApplicationNumbers++;
		break;

	case GhostLuaApplication:
		luaApplicationNumbers++;
		break;

	default:
		return GhostErrorAppInfoIllegal;
		break;
	}

	// Add application info to list.
	if (applicationList == NULL)
	{
		applicationList = GhostMemMgrMalloc(sizeof(GhostAppHandleList_t));
		if (applicationList == NULL)
		{
			return GhostErrorAppOutOfMemory;
		}
		memcpy(&(applicationList->CurrentApplicationInfo), ApplicationInfo, sizeof(GhostAppInfo_t));
		
		// Make a copy.
		// Copy ApplicationName.
		int bufferLen = strlen(ApplicationInfo->ApplicationName) + 1;
		applicationList->CurrentApplicationInfo.ApplicationName = GhostMemMgrMalloc(bufferLen);
		if (applicationList->CurrentApplicationInfo.ApplicationName == NULL)
		{
			return GhostErrorAppOutOfMemory;
		}
		memcpy(applicationList->CurrentApplicationInfo.ApplicationName, ApplicationInfo->ApplicationName, bufferLen);
		// Copy PackageName.
		bufferLen = strlen(ApplicationInfo->PackageName) + 1;
		applicationList->CurrentApplicationInfo.PackageName = GhostMemMgrMalloc(bufferLen);
		if (applicationList->CurrentApplicationInfo.PackageName == NULL)
		{
			return GhostErrorAppOutOfMemory;
		}
		memcpy(applicationList->CurrentApplicationInfo.PackageName, ApplicationInfo->PackageName, bufferLen);

		applicationList->NextApplicatonNode = NULL;
		nextApplicatonNode = &(applicationList->NextApplicatonNode);
	}
	else {
		GhostAppHandleList_t* tempNode = GhostMemMgrMalloc(sizeof(GhostAppHandleList_t));
		if (tempNode == NULL)
		{
			return GhostErrorAppOutOfMemory;
		}
		memcpy(&tempNode->CurrentApplicationInfo, ApplicationInfo, sizeof(GhostAppHandleList_t));
		
		// Make a copy.
		// Copy ApplicationName.
		int bufferLen = strlen(ApplicationInfo->ApplicationName) + 1;
		tempNode->CurrentApplicationInfo.ApplicationName = GhostMemMgrMalloc(bufferLen);
		if (tempNode->CurrentApplicationInfo.ApplicationName == NULL)
		{
			return GhostErrorAppOutOfMemory;
		}
		memcpy(tempNode->CurrentApplicationInfo.ApplicationName, ApplicationInfo->ApplicationName, bufferLen);
		// Copy PackageName.
		bufferLen = strlen(ApplicationInfo->PackageName) + 1;
		tempNode->CurrentApplicationInfo.PackageName = GhostMemMgrMalloc(bufferLen);
		if (tempNode->CurrentApplicationInfo.PackageName == NULL)
		{
			return GhostErrorAppOutOfMemory;
		}
		memcpy(tempNode->CurrentApplicationInfo.PackageName, ApplicationInfo->PackageName, bufferLen);

		tempNode->NextApplicatonNode = NULL;
		*nextApplicatonNode = tempNode;
		nextApplicatonNode = &(tempNode->NextApplicatonNode);
	}

	if (ApplicationInfo->ApplicationType == GhostNativeApplication)
	{
		applicationList->GhostAppStatus.Permission = GhostAppPermissionsNativeApplication;
	}
	else {
		applicationList->GhostAppStatus.Permission = GhostAppPermissionsNormalUser;
	}
	applicationList->GhostAppStatus.RunningStatus = GhostAppNotRunning;

	applicationList->GhostAppStatus.HaveVirtualScreen = 0;

	return GhostOK;
}

/// <summary>
/// Get appliaction info by package name.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="ApplicationInfo">Pointor of Application info.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrGetInfoByPackageName(char* PackageName, GhostAppInfo_t* const ApplicationInfo)
{
	const GhostAppHandleList_t* ptr = applicationList;
	while (ptr != NULL)
	{
		if (!strncmp(ptr->CurrentApplicationInfo.PackageName, PackageName, strlen(PackageName)))
		{
			*ApplicationInfo = ptr->CurrentApplicationInfo;
			// Make a copy.
			// Copy PackageName.
			int bufferSize = strlen(ApplicationInfo->PackageName) + 1;
			*ApplicationInfo->PackageName = GhostMemMgrMalloc(bufferSize);
			if (*ApplicationInfo->PackageName != NULL)
			{
				memcpy(ApplicationInfo->PackageName, ptr->CurrentApplicationInfo.PackageName, bufferSize);
			}
			else {
				return GhostErrorAppOutOfMemory;
			}
			
			// Copy ApplicationName.
			bufferSize = strlen(ApplicationInfo->ApplicationName) + 1;
			*ApplicationInfo->ApplicationName = GhostMemMgrMalloc(bufferSize);
			if (*ApplicationInfo->ApplicationName != NULL)
			{
				memcpy(ApplicationInfo->ApplicationName, ptr->CurrentApplicationInfo.ApplicationName, bufferSize);
			}
			else {
				return GhostErrorAppOutOfMemory;
			}
			
			return GhostOK;
		}
		else {
			ptr = ptr->NextApplicatonNode;
		}
	}
	return GhostErrorAppNotFound;
}

/// <summary>
/// Get appliaction handle node by package name.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="ApplicationInfo">Pointor of Application handle node.</param>
/// <returns>Function execution result.</returns>
static GhostError_t ghostAppMgrGetHandleNodeByPackageName(const char* PackageName, GhostAppHandleList_t** ApplicationNode)
{
	const GhostAppHandleList_t* ptr = applicationList;
	while (ptr != NULL)
	{
		if (!strncmp(ptr->CurrentApplicationInfo.PackageName, PackageName, strlen(PackageName)))
		{
			*ApplicationNode = ptr;
			return GhostOK;
		}
		else {
			ptr = ptr->NextApplicatonNode;
		}
	}
	return GhostErrorAppNotFound;
}

/// <summary>
/// Get appliaction handle node by package name.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="ApplicationInfo">Pointor of Application handle node.</param>
/// <returns>Function execution result.</returns>
static GhostError_t ghostAppMgrGetHandleNodeByAppInfo(const GhostAppInfo_t* AppInfo, GhostAppHandleList_t** ApplicationNode)
{

}

/// <summary>
/// Run an app in foreground.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrRunForeground(const char* const PackageName, int Argc, void** Args)
{
	GhostAppHandleList_t* nodePtr;
	GhostLogTerminateIfErr(Fatal, ghostAppMgrGetHandleNodeByPackageName(PackageName, &nodePtr));

	if (nodePtr->GhostAppStatus.RunningStatus == GhostAppRunningForeground)
	{
		return GhostOK;
	}

	GhostLogTerminateIfErr(Fatal, 
		GhostThreadCreate(
			&nodePtr->ThreadHandle,
			nodePtr->CurrentApplicationInfo.ApplicationEntryFunction,
			nodePtr->CurrentApplicationInfo.PackageName,
			0,
			NULL,
			1
		)
	);

	nodePtr->GhostAppStatus.RunningStatus = GhostAppRunningForeground;

	return GhostOK;
}


/// <summary>
/// Run an app in background.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrRunBackground(const char* const PackageName, int Argc, void** Args)
{
	GhostAppHandleList_t* nodePtr;
	GhostLogTerminateIfErr(Fatal, ghostAppMgrGetHandleNodeByPackageName(PackageName, &nodePtr));

	if (nodePtr->GhostAppStatus.RunningStatus == GhostAppRunningBackground)
	{
		return GhostOK;
	}

	GhostLogTerminateIfErr(Fatal,
		GhostThreadCreate(
			&nodePtr->ThreadHandle,
			nodePtr->CurrentApplicationInfo.ApplicationEntryFunction,
			nodePtr->CurrentApplicationInfo.PackageName,
			0,
			NULL,
			1
		)
	);

	nodePtr->GhostAppStatus.RunningStatus = GhostAppRunningForeground;

	return GhostOK;
}


/// <summary>
/// Stop app by appliaction info.
/// </summary>
/// <param name="ApplicationInfo"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppMgrStopApp(const GhostAppInfo_t* ApplicationInfo)
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
	GhostAppInfo_t info;
	GhostLogTerminateIfErr(Error, GhostAppMgrGetInfoByPackageName(PackageName, &info));
	GhostLogTerminateIfErr(Error, GhostAppMgrStopApp(&info));

	// Delete files.
	// TODO:

	return GhostOK;
}

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


/// <summary>
/// Open the file by the pointer of application info.
///		**After the file is opened, you can use `GhostFS` to operate the file.**
/// </summary>
/// <param name="AppInfoPtr">Pointor of application info.</param>
/// <param name="FilePtr">Pointor of file.</param>
/// <param name="AbsPath">Absolute path of the file to open.</param>
/// <param name="Mode">Mode.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppOpenFile(const GhostAppInfo_t* const AppInfoPtr, GhostFile_t* FilePtr, const char* AbsPath, char* Mode)
{
	if (AppInfoPtr->ApplicationType == GhostNativeApplication)
	{
		// TODO: Check Mode and path.

		// Open file.
		GhostLogTerminateIfErr(Error, GhostFS_Open(AbsPath, FilePtr, Mode));
	}
	else
	{
#if(MacroAllowRoot)
		// Check whether it is a root user.
		// TODO:




#endif

		// Get real path.
		char realPath[MacroMaximumPathLength] = { '\0' };
		GhostLogTerminateIfErr(Error, GhostFS_GetRealPath(AbsPath, realPath, MacroMaximumPathLength));

		// Check whether the path is legal.
	}

	return GhostOK;
}


/// <summary>
/// Get virtual screen by the pointer of application info.
/// </summary>
/// <param name="AppInfoPtr">Pointor of application info.</param>
/// <param name="ScreenPtr">Pointor of virtual screen.(pointor to lv_obj_t*)</param>
/// <returns>Function execution result.</returns>
/// TODO: Release page automatically when releasing the running program.
GhostError_t GhostAppGetVirtualScreen(const GhostAppInfo_t* const AppInfoPtr, lv_obj_t** const ScreenPtr)
{
	//GhostLogIfError(Warning, GhostLV_Lock());
	GhostLV_Lock();
	lv_obj_t* screen = lv_obj_create(lv_scr_act());
	
	if (screen != NULL)
	{
		// TODO: Check front or background.
		// lv_obj_add_flag(screen, LV_OBJ_FLAG_HIDDEN);

		// Set style.
		int width, height, radius;
		GhostScreenGetResolution(&width, &height);
		GhostScreenGetRadius(&radius);
		lv_style_set_radius(&screenStyle, radius);
		lv_obj_add_style(screen, &screenStyle, 0);
		lv_obj_set_scrollbar_mode(screen, LV_SCROLLBAR_MODE_OFF);
		lv_obj_set_pos(screen, 0, 0);
		lv_obj_set_size(screen, width, height);

	}
	
	GhostLogIfError(Warning, GhostLV_Unlock());
	if (screen == NULL)
	{

	}
	else {
		*ScreenPtr = screen;
		//*VirtualScreen = screen;
		return GhostOK;
	}

	return GhostOK;
}
