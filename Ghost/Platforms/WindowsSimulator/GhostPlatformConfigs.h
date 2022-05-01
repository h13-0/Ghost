#pragma once
#include "DeclareStructure.h"

// Ghost system configs.
/// Application Register.
//// Ghost system.
#define MacroGhostSystemInfo                       MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "Ghost System", "tech.h13.ghost", NULL, NULL)
//// Ghost launcher.
#define MacroGhostLauncherInfo                     MacroDeclareStructure(GhostApplicationInfo_t, GhostNativeApplication, "Ghost Launcher", "tech.h13.ghost.launcher", GhostLauncherRun, NULL)

#define MacroIsCalculatorEnabled                   (1)


// Ghost user configs.
#define MacroAllowRoot                        (1)

// Virtual Screen configs.
#define MacroDisplayHorizontalResolution      (240)
#define MacroDisplayVerticalResolution        (240)
