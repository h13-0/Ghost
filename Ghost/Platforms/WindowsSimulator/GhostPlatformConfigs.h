#pragma once
#include "DeclareStructure.h"

// Ghost platform configs.
/// Virtual Screen configs.
#define MacroDisplayHorizontalResolution           (240)
#define MacroDisplayVerticalResolution             (240)
/// File system configs.
#define MacroFileSystemMountPoint                  ("./Ghost")
#define MacroMaximumPathLength                     (256)

/*******************************************************/

// Ghost system configs.
/// Application Register.
//// Ghost system.
#define MacroGhostSystemInfo                       MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "Ghost System", "tech.h13.ghost", NULL, NULL)
//// Ghost launcher.
#define MacroGhostLauncherInfo                     MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "Ghost Launcher", "tech.h13.ghost.launcher", GhostLauncherRun, NULL)
#define MacroGhostLauncherConfigFileName           ("")
//// Ghost calculator
#define MacroIsCalculatorEnabled                   (1)

//// Ghost user configs.
#define MacroAllowRoot	                           (1)
#define MacroWhoAmI                                ("h13")


