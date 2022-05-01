#pragma once

#include "GhostSoftwareErrorDefine.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GhostErrorAppMgrUninitialized        DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 1)
#define GhostErrorAppInfoIllegal             DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 2)
#define GhostErrorAppNotFound                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 3)
#define GhostErrorAppDuplicatePackageName    DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 4)
#define GhostErrorAppCreateThreadError       DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 5)
#define GhostErrorAppCreateOutOfMemory       DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 6)
	/// <summary>
	/// Typedef of Ghost application type.
	/// </summary>
	typedef enum
	{
		GhostNativeApplication,
		GhostLuaApplication,
		//GhostMicropythonApplication,
	} GhostApplicationType_t;
	
	/// <summary>
	/// Typedef of Ghost application info.
	/// </summary>
	typedef struct
	{
		GhostApplicationType_t ApplicationType;
		char* PackageName;
		char* ApplicationName;
		GhostError_t(*ApplicationEntryFunction)(int Argc, void** Args);
		GhostError_t(*ApplicationDestructorFunction)(char** TranceBackMsg);
	} GhostApplicationInfo_t;

	/// <summary>
	/// Init Ghost application manager.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhostError_t GhostAppMgrInit(void);

	/// <summary>
	/// Register an app to the app list.
	/// </summary>
	/// <param name="Application">Application info.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrRegister(GhostApplicationInfo_t* Application);
	
	/// <summary>
	/// Get appliaction info by package name.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <param name="ApplicationInfo">Pointor of Application info.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrGetInfoByPackageName(char* PackageName, GhostApplicationInfo_t* ApplicationInfo);

	/// <summary>
	/// Uninstall an app.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrUninstall(char* PackageName);

	/// <summary>
	/// Run an app in foreground.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <param name="Argc">Number of args.</param>
	/// <param name="Args">Pointers of args.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrRunForeground(char* PackageName, int Argc, void** Args);
	
	/// <summary>
	/// Run an app in background.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <param name="Argc">Number of args.</param>
	/// <param name="Args">Pointers of args.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrRunBackground(char* PackageName, int Argc, void** Args);

	/// <summary>
	/// The linked list typedef of GhostApplicationList.
	/// </summary>
	typedef struct GhostApplicationList
	{
		// Application message.
		GhostApplicationInfo_t CurrentApplicationInfo;

		// Next node.
		struct GhostApplicationList* NextApplicatonNode;
	} GhostApplicationList_t;

	/// <summary>
	/// Generate application list.
	///		**The `ApplicationListPtr` should be released after use!**
	/// </summary>
	/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrGenerateApplicationList(GhostApplicationList_t* ApplicationListPtr);

	/// <summary>
	/// Release application list.
	/// </summary>
	/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrDestoryApplicationList(GhostApplicationList_t* ApplicationListPtr);

#ifdef __cplusplus
}
#endif
