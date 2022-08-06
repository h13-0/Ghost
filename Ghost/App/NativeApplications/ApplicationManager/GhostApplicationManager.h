#pragma once

#include "GhostSoftwareErrorDefine.h"
#include <stdbool.h>

#include "GhostFileSystem.h"
#include "GhostLog.h"
#include "cJSON.h"
#include "safe_lvgl.h"


//TODO: Use __COUNTER__
#define GhostErrorAppMgrUninitialized        DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 1)
#define GhostErrorAppInfoIllegal             DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 2)
#define GhostErrorAppOutOfMemory             DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 3)
#define GhostErrorAppNotFound                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 4)
#define GhostErrorAppDuplicatePackageName    DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 5)
#define GhostErrorAppCreateThreadError       DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 6)
#define GhostErrorAppConfigFileTooLarge      DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppMgrError, 7)


#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// Init Ghost application manager.
	/// </summary>
	/// <param name="void"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrInit(void);


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
	///		There are two memory management methods in this structure:
	///		1. Construction method using key value:
	///			In this case, you need to ensure the life cycle of the variable key value.
	///			Appropriate instance:
	///			```C
	///				GhostAppInfo_t info;
	///				info.ApplicationType = GhostNativeApplication;
	///				info.PackageName = "tech.h13.ghost";
	///				info... //Other application info..
	///				GhostAppMgrRegister(&info);
	///				// GhostAppMgrAppInfoDestory(&info); //Don't do this, it will trigger exceptions.
	///			```
	///			Error instance:
	///			```C
	///				GhostAppInfo_t info;
	///				info.ApplicationType = GhostNativeApplication;
	///				{
	///					info.PackageName = "tech.h13.ghost";
	///				}
	///				info... //Other application info..
	///				GhostAppMgrRegister(&info); //At this point, the `info.PackageName` has become a dangling pointer. Behavior undefined.
	///			```
	///			
	///		2. Use init destroy function to construct and destruct:
	///			In this case, do not change the value of key manually.
	///			Appropriate instance:
	///			```C
	///				GhostAppInfo_t info = GhostAppMgrAppInfoInit(); //Set all key values to 0.
	///				GhostAppMgrGetInfoByPackageName("tech.h13.ghost", &info);
	///				GhostAppMgrAppInfoDestory(&info); //This function must be called, otherwise memory leakage will occur.
	///			```
	///			Legal but not recommended instance:
	///			```C
	///				GhostAppInfo_t info = GhostAppMgrAppInfoInit(); //Set all key values to 0.
	///				GhostAppMgrGetInfoByPackageName("tech.h13.ghost", &info); 
	///				GhostMemMgrFree(info.PackageName);
	///				info.PackageName = GhostMemMgrCalloc(1, strlen("tech.h13.ghost") + 1);
	///				memcpy(info.PackageName, "tech.h13.ghost", strlen("tech.h13.ghost") + 1);
	///				GhostAppMgrAppInfoDestory(&info); //It's okay, but it's not recommended.
	///			```
	///			Error instance:
	///			```C
	///				GhostAppInfo_t info = GhostAppMgrAppInfoInit(); //Set all key values to 0.
	///				info.PackageName = "tech.h13.ghost"; //In this mode, do not change the key value manually, otherwise it will trigger exceptions.
	///				GhostAppMgrGetInfoByPackageName("tech.h13.ghost", &info); 
	///				GhostAppMgrAppInfoDestory(&info);
	///			```
	///			Do not use standard memory Libraries!
	///			```C
	///				GhostAppInfo_t info = GhostAppMgrAppInfoInit(); //Set all key values to 0.
	///				GhostAppMgrGetInfoByPackageName("tech.h13.ghost", &info); 
	///				GhostMemMgrFree(info.PackageName);
	///				info.PackageName = calloc(1, strlen("tech.h13.ghost") + 1);
	///				memcpy(info.PackageName, "tech.h13.ghost", strlen("tech.h13.ghost") + 1);
	///				GhostAppMgrAppInfoDestory(&info); //It's okay, but it's not recommended.
	///			```
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
	/// Initialize GhostAppInfo_t structure.
	/// </summary>
	/// <param name="void"></param>
	/// <returns>GhostAppInfo_t structure.</returns>
	static inline GhostAppInfo_t GhostAppMgrAppInfoInit(void)
	{
		return (GhostAppInfo_t) { 0 };
	}
	

	/// <summary>
	/// Free memory of GhostAppInfo_t.
	/// </summary>
	/// <param name="ApplicationInfo">Pointor of GhostAppInfo_t.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrAppInfoDestory(const GhostAppInfo_t* ApplicationInfo);


	/// <summary>
	/// Register an app to the app list.
	/// </summary>
	/// <param name="Application">Application info.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrRegister(const GhostAppInfo_t* ApplicationInfo);
	

	/// <summary>
	/// Get appliaction info by package name.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <param name="ApplicationInfo">Pointor of Application info.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrGetInfoByPackageName(char* PackageName, GhostAppInfo_t* const ApplicationInfo);


	/// <summary>
	/// Run an app in foreground.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <param name="Argc">Number of args.</param>
	/// <param name="Args">Pointers of args.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrRunForeground(const char* const PackageName, int Argc, void** Args);
	

	/// <summary>
	/// Run an app in background.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <param name="Argc">Number of args.</param>
	/// <param name="Args">Pointers of args.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrRunBackground(const char* const PackageName, int Argc, void** Args);


	/// <summary>
	/// Stop app by appliaction info.
	/// </summary>
	/// <param name="ApplicationInfo"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrStopApp(const GhostAppInfo_t* ApplicationInfo);


	/// <summary>
	/// Stop app by package name.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrStopAppByPackageName(char* PackageName);


	/// <summary>
	/// Uninstall an app.
	/// </summary>
	/// <param name="PackageName">Package name.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrUninstall(const char* PackageName);


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
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrGenerateApplicationList(GhostAppList_t* const ApplicationListPtr);
	

	/// <summary>
	/// Release application list.
	/// </summary>
	/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppMgrDestoryApplicationList(GhostAppList_t* ApplicationListPtr);


	/// <summary>
	/// The following is the API of PermissionManager.
	/// </summary>
	

#define DeclareNativeAppInfo()										static GhostAppInfo_t __applicationInfo__ = { 0 }
#define GhostAppNativeInfoInit(PackageName)                         do{ GhostLogTerminateIfErr(Fatal, GhostAppMgrGetInfoByPackageName(PackageName, &__applicationInfo__)); } while(0); GhostOK


	/// <summary>
	/// Open the file by the pointer of application info.
	///		**After the file is opened, you can use `GhostFS` to operate the file.**
	/// </summary>
	/// <param name="AppInfoPtr">Pointor of application info.</param>
	/// <param name="FilePtr">Pointor of file.</param>
	/// <param name="AbsPath">Absolute path of the file to open.</param>
	/// <param name="Mode">Mode.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppOpenFile(const GhostAppInfo_t* const AppInfoPtr, GhostFile_t* FilePtr, const char* AbsPath, char* Mode);
#define GhostNativeAppOpenFile(FilePtr, AbsPath, Mode)				GhostAppOpenFile(&__applicationInfo__, FilePtr, AbsPath, Mode)


	/// <summary>
	/// Get the default configs of the app.
	/// @note: This function should be deprecated.
	/// </summary>
	/// <param name="AppInfoPtr">Pointor of application info.</param>
	/// <param name="Configs">Configuration information in cJSON.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppGetAppConfigJSON(const GhostAppInfo_t* const AppInfoPtr, cJSON** Configs);
#define GhostNativeAppGetAppConfigJSON(Configs)						GhostAppGetAppConfigJSON(&__applicationInfo__, Configs)


	/// <summary>
	/// Get virtual screen by the pointer of application info.
	/// </summary>
	/// <param name="AppInfoPtr">Pointor of application info.</param>
	/// <param name="ScreenPtr">Pointor of virtual screen.(pointor to lv_obj_t*)</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppGetVirtualScreen(const GhostAppInfo_t* const AppInfoPtr, lv_obj_t** const ScreenPtr);
#define GhostNativeAppGetVirtualScreen(PagePtr)						GhostAppGetVirtualScreen(&__applicationInfo__, PagePtr)


	/// <summary>
	/// 
	/// </summary>
	/// <param name="AppInfoPtr"></param>
	/// <param name="Code"></param>
	/// <returns></returns>
	GhostError_t GhostAppIsForeGround(const GhostAppInfo_t* const AppInfoPtr);

	//GhostError_t GhostAppGet

#ifdef __cplusplus
}
#endif
