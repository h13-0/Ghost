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
// Define errors.
#define DeclareGhostAppFrmErrCode(ErrID) \
	DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppFrmError, ErrID)
#define GhostAppFrmErrUninited                      DeclareGhostAppFrmErrCode(1)
#define GhostAppFrmErrRepeatedInited                DeclareGhostAppFrmErrCode(2)
#define GhostAppFrmErrPointerIsNULL                 DeclareGhostAppFrmErrCode(3)
#define GhostAppFrmErrAppInfoIllegal                DeclareGhostAppFrmErrCode(4)
#define GhostAppFrmErrOutOfMemory					DeclareGhostAppFrmErrCode(5)
#define GhostAppFrmErrAppNotFound                   DeclareGhostAppFrmErrCode(6)
#define GhostAppFrmErrDuplicatePackageName			DeclareGhostAppFrmErrCode(7)
#define GhostAppFrmErrCreateThreadError				DeclareGhostAppFrmErrCode(8)
#define GhostAppFrmErrConfigFileTooLarge			DeclareGhostAppFrmErrCode(9)


/***********************************Typedefs***********************************/
#ifdef __cplusplus
EXTREN_C_START
#endif // __cplusplus

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
typedef void* GhostAppInfo_t;


/// <summary>
/// App running status.
/// Getter: `GhostAppFrmGetAppStatus`.
/// </summary>
typedef enum
{
	GhostAppStatusNotRunning,
	GhostAppStatusLoading,
	GhostAppStatusForeground,
	GhostAppStatusBackground,
	GhostAppStatusNoResponse,
	GhostAppStatusNotFound,
	GhostAppStatusNum,
} GhostAppStatus_t;


/// <summary>
/// App owner.
///		When the app owner is root, it has all permissions by default.
/// </summary>
typedef enum
{
	GhostAppOwnerNormal,
	GhostAppOwnerSystem,
	GhostAppOwnerRoot,
	GhostAppOwnerNum,
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
void GhostAppFrmAppInfoFree(GhostAppInfo_t AppInfo);


/// <summary>
/// Clone `AppInfo` to a new `GhostAppInfo_t`.
/// This function will not verify info.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="AppInfo">App info in pointor of `GhostAppInfo_t`.</param>
/// <returns> Create failed when the return value is null. </returns>
GhostAppInfo_t GhostAppFrmAppInfoClone(GhostAppInfo_t AppInfo);


/// <summary>
/// Verify whether `GhostAppInfo_t` is legal.
/// Thread safety:
///		Yes.
/// </summary>
/// <returns>GhostOK if vaild.</returns>
GhostError_t GhostAppFrmVerifyAppInfo(GhostAppInfo_t AppInfo);


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
GhostError_t GhostAppFrmRegisterApp(GhostAppInfo_t AppInfo);


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
/// <returns>
/// Returns NULL when the app does not exist or out of memory.
/// </returns>
GhostAppInfo_t GhostAppFrmGetAppInfo(const char* PackageName);


/// <summary>
/// Run an app in foreground.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmRunForeground(const char* PackageName, int Argc, char** Argv);


/// <summary>
/// Run an app in background.
/// </summary>
/// <param name="PackageName">Package name.</param>
/// <param name="Argc">Number of args.</param>
/// <param name="Args">Pointers of args.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmRunBackground(const char* PackageName, int Argc, void** Args);


/// <summary>
/// Stop app by appliaction info.
/// </summary>
/// <param name="ApplicationInfo"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppFrmStopApp(GhostAppInfo_t ApplicationInfo);


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



#ifdef __cplusplus
EXTREN_C_END
#endif // __cplusplus