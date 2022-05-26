#pragma once
#include "DeclareStructure.h"

// Ghost platform configs.
//> Virtual Screen configs.
#define MacroDisplayHorizontalResolution           (240)
#define MacroDisplayVerticalResolution             (240)
//> File system configs.
#define MacroFileSystemMountPoint                  ("./Ghost")   //**Paths should be separated by '/'**
#define MacroMaximumPathLength                     (256)

/*******************************************************/

// Ghost system configs.
//> Application Register.
//>> Ghost system.
#define MacroGhostSystemInfo                       MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "Ghost System", "tech.h13.ghost", NULL, NULL)
//>> Ghost launcher.
#if(1)
#define MacroGhostLauncherInfo                     MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "Ghost Launcher", "tech.h13.ghost.launcher", GhostLauncherRun, NULL)
#define MacroGhostLauncherConfigFileName           ("")
#endif //>> Ghost launcher.

//>> Ghost calculator
#define MacroIsCalculatorEnabled                   (1)
#if(MacroIsCalculatorEnabled)

//// Ghost calculator configs.

#endif //#if(MacroIsCalculatorEnabled)

//> Ghost user configs.
#define MacroAllowRoot	                           (1)
#define MacroWhoAmI                                ("h13")

//> Application configs.
//>> Ghost launcher configs.
//>>> Built-in themes.
#define MacroGhostLauncherThemeBigWhite            ("Big White")
#define MacroGhostLauncherThemeLiteBlack           ("Lite Black")
//>>> Default theme.
#define MacroGhostLauncherDefaultTheme             (MacroGhostLauncherThemeBigWhite)

#define MacroGhostLauncherBuiltInThemes            ()



