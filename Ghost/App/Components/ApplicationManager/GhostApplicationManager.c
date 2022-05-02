#include "GhostApplicationManager.h"
#include "GhostPlatformConfigs.h"

// Standard libraries.
#include <string.h>
#include <stdlib.h>

// Ghost drivers.
#include "GhostThread.h"

/// <summary>
/// The linked list typedef of GhostApplicationList.
/// </summary>
typedef struct GhostAppHandleList
{
	// Application message.
	GhostApplicationInfo_t CurrentApplicationInfo;

	// Status.
	bool IsRunning;
	bool IsForeground;

	// Handles.
	GhostThread_t ThreadHandle;

	// Next node.
	struct GhostAppHandleList* NextApplicatonNode;
} GhostAppHandleList_t;

static GhostAppHandleList_t* applicationList = NULL;
static GhostAppHandleList_t** nextApplicatonNode = NULL;

static int nativeApplicationNumbers = 0;
static int luaApplicationNumbers = 0;

/// <summary>
/// Init Ghost application manager.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
GhostError_t GhostAppMgrInit(void)
{
	if (nativeApplicationNumbers == 0)
	{
		// Register Ghost System.
		GhostApplicationInfo_t ghostSystem = MacroGhostSystemInfo;
		GhostAppMgrRegister(&ghostSystem);
	}
	return GhostOK;
}

/// <summary>
/// Register an app to the app list.
/// </summary>
/// <param name="ApplicationInfo">Application info.</param>
/// <returns></returns>
GhostError_t GhostAppMgrRegister(GhostApplicationInfo_t* ApplicationInfo)
{
	// TODO: Check icons.

	// Check parameters.
	// Make sure the package name is unique.
	GhostAppHandleList_t* ptr = applicationList;
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
		applicationList = malloc(sizeof(GhostAppHandleList_t));
		if (applicationList == NULL)
			return GhostErrorAppCreateOutOfMemory;
		memcpy(&(applicationList->CurrentApplicationInfo), ApplicationInfo, sizeof(GhostApplicationInfo_t));
		applicationList->NextApplicatonNode = NULL;
		nextApplicatonNode = &(applicationList->NextApplicatonNode);
	}
	else {
		*nextApplicatonNode = malloc(sizeof(GhostAppHandleList_t));
		if (*nextApplicatonNode == NULL)
			return GhostErrorAppCreateOutOfMemory;
		memcpy(&(*nextApplicatonNode)->CurrentApplicationInfo, ApplicationInfo, sizeof(GhostAppHandleList_t));
		(*nextApplicatonNode)->NextApplicatonNode = NULL;
		nextApplicatonNode = &((*nextApplicatonNode)->NextApplicatonNode);
	}

	return GhostOK;
}

/// <summary>
/// Get appliaction info by package name.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="ApplicationInfo">Pointor of Application info.</param>
/// <returns></returns>
GhostError_t GhostAppMgrGetInfoByPackageName(char* PackageName, GhostApplicationInfo_t* ApplicationInfo)
{
	GhostAppHandleList_t* ptr = applicationList;
	while (ptr != NULL)
	{
		if (!strncmp(ptr->CurrentApplicationInfo.PackageName, PackageName, strlen(PackageName)))
		{
			*ApplicationInfo = ptr->CurrentApplicationInfo;
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
/// <returns></returns>
static GhostError_t ghostAppMgrGetHandleNodeByPackageName(char* PackageName, GhostAppHandleList_t** ApplicationNode)
{
	GhostAppHandleList_t* ptr = applicationList;
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
/// Uninstall an app.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <returns></returns>
GhostError_t GhostAppMgrUninstall(char* PackageName)
{
	
	return GhostOK;
}

/// <summary>
/// Run an app in foreground.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns></returns>
GhostError_t GhostAppMgrRunForeground(char* PackageName, int Argc, void** Args)
{
	GhostAppHandleList_t* nodePtr;
	GhostError_t ret = ghostAppMgrGetHandleNodeByPackageName(PackageName, &nodePtr);
	if (ret.LayerErrorCode == GhostNoError)
	{
		ret = GhostThreadCreate(
			nodePtr->ThreadHandle,
			nodePtr->CurrentApplicationInfo.ApplicationEntryFunction,
			nodePtr->CurrentApplicationInfo.PackageName,
			0,
			NULL,
			1
		);

		return ret;
	}
	else {
		return ret;
	}
}

/// <summary>
/// Run an app in background.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns></returns>
GhostError_t GhostAppMgrRunBackground(char* PackageName, int Argc, void** Args)
{
	return GhostOK;
}

/// <summary>
/// Generate application list.
///		**The `ApplicationListPtr` should be released after use!**
/// </summary>
/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
/// <returns></returns>
GhostError_t GhostAppMgrGenerateApplicationList(GhostApplicationList_t* ApplicationListPtr)
{
	return GhostOK;
}

/// <summary>
/// Release application list.
/// </summary>
/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
/// <returns></returns>
GhostError_t GhostAppMgrDestoryApplicationList(GhostApplicationList_t* ApplicationListPtr)
{
	return GhostOK;
}
