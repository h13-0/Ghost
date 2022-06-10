#pragma once
#include "DeclareStructure.h"

// Ghost platform configs.
//> Ghost log configs.
#define MacroLogOutputInit(OutputStreamListPtr, OutputNum)				do{ \
																			OutputStreamListPtr = calloc(sizeof(FILE*), 1); \
																			*OutputStreamListPtr = stdout; \
																			OutputNum = 1; \
																			if(0) { return GhostErrorLogInitFailed; } \
																		}while(0)

//> Virtual Screen configs.
#define MacroDisplayHorizontalResolution            (240)
#define MacroDisplayVerticalResolution              (240)
//> File system configs.
#define MacroFileSystemMountPoint                   ("./Ghost")   //**Paths should be separated by '/'**
#define MacroMaximumPathLength                      (256)

/*******************************************************/

// Ghost system configs.
#define MacroSystemName                             ("Ghost")
#define MacroSystemVersion                          ("")         // TODO: Reference cmake version number.
//> Ghost components configs.
//>> Application manager configs.

#define MacroGhostAppPackageInformationFileName     ("App.json")
#define MacroGhostAppDefaultConfigFileName          ("Configs.json")
#define MacroGhostAppDefaultConfigFileSizeLimit     (4096)       // 4KB.

//> Ghost user configs.
#define MacroAllowRoot	                            (1)
#define MacroWhoAmI                                 ("h13")


//> Application configs.
//>> Ghost launcher configs.
//>>> Built-in themes.
#define MacroGhostLauncherThemeBigWhite             ("Big White")
#define MacroGhostLauncherThemeLiteBlack            ("Lite Black")
//>>> Default theme.
#define MacroGhostLauncherDefaultTheme              (MacroGhostLauncherThemeBigWhite)

#define MacroGhostLauncherBuiltInThemes             ()

//> Register native applications.
//>> Ghost system.
#define MacroGhostSystemInfo                        MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "tech.h13.ghost", "Ghost System", 0, NULL, NULL)
//>> Ghost Permission Manager.
#if(1)
#define MacroGhostPM_PackageName                    MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "tech.h13.ghost.permissionmanager", "Ghost Permission Manager", 0, GhostPermissionManagerRun, NULL)
#endif

//>> Ghost launcher.
#if(1)
#define MacroGhostLauncherPackageName               ("tech.h13.ghost.launcher")
#define MacroGhostLauncherInfo                      MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "tech.h13.ghost.launcher", "Ghost Launcher", 0, GhostLauncherRun, NULL)
#define MacroGhostLauncherConfigFileName            ("")
#endif //>> Ghost launcher.

//>> Ghost calculator
#define MacroIsCalculatorEnabled                    (1)
#if(MacroIsCalculatorEnabled)

//// Ghost calculator configs.

#endif //#if(MacroIsCalculatorEnabled)

