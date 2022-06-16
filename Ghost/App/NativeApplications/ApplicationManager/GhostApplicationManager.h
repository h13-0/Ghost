#pragma once

#include "GhostSoftwareErrorDefine.h"
#include <stdbool.h>

#include "GhostFileSystem.h"
#include "GhostLog.h"
#include "cJSON.h"


#define GhostErrorAppMgrUninitialized        DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 1)
#define GhostErrorAppInfoIllegal             DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 2)
#define GhostErrorAppNotFound                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 3)
#define GhostErrorAppDuplicatePackageName    DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 4)
#define GhostErrorAppCreateThreadError       DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 5)
#define GhostErrorAppCreateOutOfMemory       DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 6)
#define GhostErrorAppConfigFileTooLarge      DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 7)


#ifdef __cplusplus
extern "C" {
#endif

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
		int Version;
		GhostError_t(*ApplicationEntryFunction)(int Argc, void** Args);
		GhostError_t(*ApplicationDestructorFunction)(char** TranceBackMsg);
	} GhostAppInfo_t;


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
	GhostError_t GhostAppMgrRegister(GhostAppInfo_t* Application);
	

	/// <summary>
	/// Get appliaction info by package name.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <param name="ApplicationInfo">Pointor of Application info.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrGetInfoByPackageName(char* PackageName, GhostAppInfo_t* ApplicationInfo);


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
		GhostAppInfo_t CurrentApplicationInfo;

		// Next node.
		struct GhostApplicationList* NextApplicatonNode;
	} GhostAppList_t;


	/// <summary>
	/// Generate application list.
	///		**The `ApplicationListPtr` should be released after use!**
	/// </summary>
	/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrGenerateApplicationList(GhostAppList_t* ApplicationListPtr);
	

	/// <summary>
	/// Release application list.
	/// </summary>
	/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrDestoryApplicationList(GhostAppList_t* ApplicationListPtr);


	/// <summary>
	/// Get the default configs of the app.
	/// @note: This function should be deprecated.
	/// </summary>
	/// <param name="Application">Application info.</param>
	/// <param name="Configs">Configuration information in cJSON.</param>
	/// <returns></returns>
	GhostError_t GhostAppMgrGetAppConfigJSON(GhostAppInfo_t* Application, cJSON** Configs);


	/// <summary>
	/// The following is the API of PermissionManager.
	/// </summary>
	

#define DeclareNativeAppInfo()										static GhostAppInfo_t __applicationInfo__;
#define GhostAppNativeInfoInit(PackageName)                         do{ GhostLogRetIfErr(Fatal, GhostAppMgrGetInfoByPackageName(PackageName, &__applicationInfo__)); } while(0); GhostOK


	/// <summary>
	/// Open the file by the pointer of application info.
	///		**After the file is opened, you can use `GhostFS` to operate the file.**
	/// </summary>
	/// <param name="AppInfoPtr">Pointor of application info.</param>
	/// <param name="FilePtr">Pointor of file.</param>
	/// <param name="AbsPath">Absolute path of the file to open.</param>
	/// <param name="Mode">Mode.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppOpenFile(const GhostAppInfo_t* AppInfoPtr, GhostFile_t* FilePtr, const char* AbsPath, char* Mode);
#define GhostNativeAppOpenFile(FilePtr, AbsPath, Mode)				GhostAppOpenFile(&__applicationInfo__, FilePtr, AbsPath, Mode)


	/// <summary>
	/// Get the default configs of the app.
	/// @note: This function should be deprecated.
	/// </summary>
	/// <param name="AppInfoPtr">Pointor of application info.</param>
	/// <param name="Configs">Configuration information in cJSON.</param>
	/// <returns></returns>
	GhostError_t GhostAppGetAppConfigJSON(const GhostAppInfo_t* AppInfoPtr, cJSON** Configs);
#define GhostNativeAppGetAppConfigJSON(Configs)						GhostAppGetAppConfigJSON(&__applicationInfo__, Configs)


#ifdef __cplusplus
}
#endif
