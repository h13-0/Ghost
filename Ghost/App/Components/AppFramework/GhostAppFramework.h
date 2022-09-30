#pragma once
/*******************************************************************************
 * @File   : GhostApplicationFramework.h
 * @Path   : App/Components/ApplicationFramework/GhostApplicationFramework.h
 * @Module : Application framework
 *
 * @Author : h13
 * @Time   : 2022/9/24 23:48:26
 * @license: AGPL-3.0(https://github.com/h13-0/Ghost/blob/master/LICENSE)
 * @Notes  :
 *		
 *
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"
// Self headers.

// Standard headers.
#include <stdbool.h>

// Thirdparty headers.
#include "cJSON.h"

// Ghost headers.
#include "GhostSoftwareErrorDefine.h"
#include "GhostFileSystem.h"
#include "GhostLog.h"
#include "safe_lvgl.h"

/***********************************Defines************************************/
#define DeclareGhostAppFrmErrCode() \
	DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppFrmError, __COUNTER__)
#define GhostAppFrmErrUninited                      DeclareGhostAppFrmErrCode()
#define GhostAppFrmErrRepeatedInited                DeclareGhostAppFrmErrCode()
#define GhostAppFrmErrPointerIsNULL                 DeclareGhostAppFrmErrCode()
#define GhostAppFrmErrAppInfoIllegal                DeclareGhostAppFrmErrCode()
#define GhostAppFrmErrOutOfMemory					DeclareGhostAppFrmErrCode()
#define GhostAppFrmErrAppNotFound                   DeclareGhostAppFrmErrCode()
#define GhostAppFrmErrDuplicatePackageName			DeclareGhostAppFrmErrCode()
#define GhostAppFrmErrCreateThreadError				DeclareGhostAppFrmErrCode()
#define GhostAppFrmErrConfigFileTooLarge			DeclareGhostAppFrmErrCode()


/***********************************Typedefs***********************************/
EXTREN_C_START

/// <summary>
/// Typedef of Ghost application type.
/// Getter: ``
/// Setter: ``
/// </summary>
typedef enum
{
	GhostAppTypeNative,
	GhostAppTypeLua,
	//GhostAppTypeMicropython,  // TODO.
	GhostAppTypeNum,
} GhostAppType_t;


/// <summary>
/// Typedef of Ghost application info.
/// Getter: 
///		`GhostAppFrmAppInfoNew`
///		`GhostAppFrmAppInfoClone`
/// 
/// </summary>
typedef struct __ghostAppInfo
{
	GhostAppType_t AppType;
	char* PackageName;
	char* AppName;
	char* IconPath;                                                     // Optional.
	int Version;
	GhostError_t(*EntryHandle)(int Argc, void** Args);
	GhostError_t(*DestoryHandle)(int Countdown, char** TranceBackMsg);  // Optional.
};
typedef struct __ghostAppInfo* GhostAppInfo_t;


/// <summary>
/// App running status.
/// Getter: `GhostAppFrmGetAppStatus`.
/// </summary>
typedef enum
{
	GhostAppStatusNotRunning,
	GhostAppStatusForeground,
	GhostAppStatusBackground,
	GhostAppStatusNotInstalled,
	GhostAppStatusNum,
} GhostAppStatus_t;


/// <summary>
/// App owner.
///		When the app owner is root, it has all permissions by default.
/// </summary>
typedef enum
{
	GhostAppOwnerNormal = 0,
	GhostAppOwnerSystem = 1,
	GhostAppOwnerRoot = 2,
} GhostAppOwner_t;


/// <summary>
/// 
/// </summary>
typedef struct GhostAppAuthorization
{
	// Run authorization.
	bool GhostAppAuthRunBackground : 1;   // Run background.
	bool GhostAppAuthIgnPwrSaving : 1;    // Ignore power saving.

	// File access authorization.
	bool GhostAppAuthReadSD_Card : 1;     // Read files in sd card.
	bool GhostAppAuthWriteSD_Card : 1;    // Write files in sd card.
	bool GhostAppAuthReadSysFile : 1;     // Read system files, `GhostAppOwnerSystem` or `GhostAppOwnerRoot` required.
	bool GhostAppAuthWriteSysFile : 1;    // Read system files, `GhostAppOwnerSystem` or `GhostAppOwnerRoot` required.
	bool GhostAppAuthReadSysFmwFile : 1;  // Read system firmware files, `GhostAppOwnerSystem` or `GhostAppOwnerRoot` required.
	bool GhostAppAuthWriteSysFmwFile : 1; // Write system firmware files, Root required.

	// 
	bool GhostAppAuthModifySettings : 1;  // Including power mode, ..


} GhostAppAuth_t;


/**********************************Prototypes**********************************/
/// <summary>
/// Init Ghost application framework.
/// Thread safety:
///		Unsafe first run.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmInit(void);


/// <summary>
/// Query app status using package name.
/// Thread safety:
///		Yes.
/// </summary>
/// <returns>Ghost app status in GhostAppStatus_t.</returns>
GhostAppStatus_t GhostAppFrmGetAppStatus(const char* PackageName);


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
	GhostError_t(*DestoryHandle)(int Countdown, char** TranceBackMsg));


/// <summary>
/// Free memory of `GhostAppInfo_t`.
/// </summary>
/// <param name="AppInfo">App info in pointor of `GhostAppInfo_t`.</param>
void GhostAppFrmAppInfoFree(const GhostAppInfo_t AppInfo);


/// <summary>
/// Clone `AppInfo` to a new `GhostAppInfo_t`.
/// This function will not verify info.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="AppInfo">App info in pointor of `GhostAppInfo_t`.</param>
/// <returns> Create failed when the return value is null. </returns>
GhostAppInfo_t GhostAppFrmAppInfoClone(const GhostAppInfo_t AppInfo);


/// <summary>
/// Verify whether `GhostAppInfo_t` is legal.
/// Thread safety:
///		Yes.
/// </summary>
/// <returns>GhostOK if vaild.</returns>
GhostError_t GhostAppFrmVerifyAppInfo(const GhostAppInfo_t AppInfo);


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
GhostError_t GhostAppFrmRegisterApp(const GhostAppInfo_t AppInfo);


/// <summary>
/// Get pointor of application handle in Ghost App Framework.
/// This method is a DAGEROUS operation and only allowed for Ghost system.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="PackageName"></param>
/// <returns>Returns NULL when the app does not exist.</returns>
void* GhostAppFrmGetAppHandle(const char* PackageName);


/// <summary>
/// Get appliaction info by package name.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <returns>Create failed when the return value is null.</returns>
GhostAppInfo_t GhostAppFrmGetAppInfo(const char* PackageName);


/// <summary>
/// Run an app in foreground.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmRunForeground(const char* const PackageName, int Argc, void** Args);


/// <summary>
/// Run an app in background.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmRunBackground(const char* const PackageName, int Argc, void** Args);


/// <summary>
/// Stop app by appliaction info.
/// </summary>
/// <param name="ApplicationInfo"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmStopApp(const GhostAppInfo_t ApplicationInfo);


/// <summary>
/// Stop app by package name.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmStopAppByPackageName(char* PackageName);


/// <summary>
/// Uninstall an app.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmUninstall(const char* PackageName);


/*
/// <summary>
/// Generate application list.
///		**The `ApplicationListPtr` should be released after use!**
/// </summary>
/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmGenerateApplicationList(GhostAppList_t* const ApplicationListPtr);


/// <summary>
/// Release application list.
/// </summary>
/// <param name="ApplicationListPtr">Pointer of application linked list.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmDestoryApplicationList(GhostAppList_t* ApplicationListPtr);
*/



EXTREN_C_END

#ifdef __cplusplus
extern "C" {
#endif




	


	/// <summary>
	/// The following is the API of PermissionManager.
	/// </summary>
	

#define DeclareNativeAppInfo()										static GhostAppInfo_t __applicationInfo__ = { 0 }
#define GhostAppNativeInfoInit(PackageName)                         do{ GhostLogTerminateIfErr(Fatal, GhostAppFrmGetInfoByPackageName(PackageName, &__applicationInfo__)); } while(0); GhostOK


	/// <summary>
	/// Open the file by the pointer of application info.
	///		**After the file is opened, you can use `GhostFS` to operate the file.**
	/// </summary>
	/// <param name="AppInfoPtr">Pointor of application info.</param>
	/// <param name="FilePtr">Pointor of file.</param>
	/// <param name="AbsPath">Absolute path of the file to open.</param>
	/// <param name="Mode">Mode.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppOpenFile(const GhostAppInfo_t AppInfoPtr, GhostFile_t* FilePtr, const char* AbsPath, char* Mode);
#define GhostNativeAppOpenFile(FilePtr, AbsPath, Mode)				GhostAppOpenFile(&__applicationInfo__, FilePtr, AbsPath, Mode)


	/// <summary>
	/// Get the default configs of the app.
	/// @note: This function should be deprecated.
	/// </summary>
	/// <param name="AppInfoPtr">Pointor of application info.</param>
	/// <param name="Configs">Configuration information in cJSON.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppGetAppConfigJSON(const GhostAppInfo_t AppInfoPtr, cJSON** Configs);
#define GhostNativeAppGetAppConfigJSON(Configs)						GhostAppGetAppConfigJSON(&__applicationInfo__, Configs)


	/// <summary>
	/// Get virtual screen by the pointer of application info.
	/// </summary>
	/// <param name="AppInfoPtr">Pointor of application info.</param>
	/// <param name="ScreenPtr">Pointor of virtual screen.(pointor to lv_obj_t*)</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostAppGetVirtualScreen(const GhostAppInfo_t AppInfoPtr, lv_obj_t** const ScreenPtr);
#define GhostNativeAppGetVirtualScreen(PagePtr)						GhostAppGetVirtualScreen(&__applicationInfo__, PagePtr)


	/// <summary>
	/// 
	/// </summary>
	/// <param name="AppInfoPtr"></param>
	/// <param name="Code"></param>
	/// <returns></returns>
	GhostError_t GhostAppIsForeGround(const GhostAppInfo_t AppInfoPtr);

	//GhostError_t GhostAppGet

#ifdef __cplusplus
}
#endif
