#pragma once
#include "DeclareStructure.h"

/****************************************************** Ghost common declarations ******************************************************/
#define MacroGhostMemOptStrict                                        (1)
#define MacroGhostMemOptNormal                                        (2)
#define MacroGhostMemOptExperience                                    (3)

#define MacroGhostSizeOptStrict                                       (1)
#define MacroGhostSizeOptNormal                                       (2)
#define MacroGhostSizeOptExperience                                   (3)


/******************************************************* Ghost platform configs *******************************************************/
//> Virtual Screen configs.
#define MacroDisplayHorizontalResolution                              (240)
#define MacroDisplayVerticalResolution                                (240)
#define MacroDisplayFilletRadius                                      (10)

//> 
#define MacroDisplayMaximumHorizontalResolution                       (1080)
#define MacroDisplayMaximumVerticalResolution                         (1080)


/******************************************************** Ghost driver configs ********************************************************/
//> File system configs.
#define MacroFileSystemMountPoint                                     ("./Ghost")   //**Paths should be separated by '/'**
#define MacroMaximumPathLength                                        (256)


/********************************************************* Ghost app configs **********************************************************/
//> Ghost system configs.
#if(1)
#define MacroSystemName                                               ("Ghost")
#define MacroSystemVersion                                            ("")         // TODO: Reference cmake version number.

//>> Memory optimization.
#define MacroGhostSystemMemOptimizeLevel                              (MacroGhostMemOptExperience)
#define MacroGhostSystemSizeOptimizeLevel                             (MacroGhostSizeOptExperience)

#endif // Ghost system configs.


//> Ghost user configs.
#if(1)
#define MacroAllowRoot                                                (1)
#define MacroWhoAmI                                                   ("h13")
#endif // Ghost user configs.


//> Ghost components configs.
//>> Ghost log configs.
#if(1)
#define MacroGhostLogOutputInit(OutputStreamListPtr, OutputNum)       do{ \
                                                                            OutputStreamListPtr = calloc(sizeof(FILE*), 1); \
                                                                            *OutputStreamListPtr = stdout; \
                                                                            OutputNum = 1; \
                                                                            if(0) { return GhostErrorLogInitFailed; } \
                                                                        }while(0)

#define MacroGhostLogMinimumLogLevel                                  (Debug)



#if defined(_DEBUG)
#define MacroGhostLogOutputFileName                                   (1)
#define MacroGhostLogOutputLineNumber                                 (1)

#else // #if defined(_DEBUG)
#warning "TODO"
#if(MacroGhostSystemSizeOptimizeLevel == MacroGhostSizeOptExperience)

#elif(MacroGhostSystemSizeOptimizeLevel == MacroGhostMemOptNormal)

#else //#if(MacroGhostSystemSizeOptimizeLevel == MacroGhostSizeOptExperience)

#endif //#if(MacroGhostSystemSizeOptimizeLevel == MacroGhostSizeOptExperience)

#endif // #if defined(_DEBUG)

#endif // Ghost log configs.

//> Ghost Native applications configs.
//>> Application manager configs.
#define MacroGhostAppPackageInformationFileName                       ("App.json")
#define MacroGhostAppDefaultConfigFileName                            ("Configs.json")
#define MacroGhostAppDefaultConfigFileSizeLimit                       (4096)       // 4KB.

//> Ghost theme manager.
//>>> Built-in themes.

// TODO: Register themes instead of declaring themes.
//#define MacroGhostLauncherThemeBigWhite                               ("Big White")
//#define MacroGhostLauncherThemeLiteBlack                              ("Lite Black")
#define MacroGhostLauncherThemeAppleLike                              ("Apple Like")
#define MacroGhostLauncherThemeCunstomBackground                      ()
#if defined(MacroGhostLauncherThemeAppleLike)



#endif //#if defined(MacroGhostLauncherThemeAppleLike)

#define MacroGhostLauncherBuiltInThemes                               ()


//> Ghost launcher configs.
//>> Default theme.
#define MacroGhostLauncherDefaultTheme                                (MacroGhostLauncherThemeAppleLike)
//>> Advanced configs.
#define MacroGhostLauncherMemOptimizeLevel                            (MacroGhostSystemMemOptimizeLevel)

//>> Ghost calculator.
#define MacroIsCalculatorEnabled                                      (1)
#if(MacroIsCalculatorEnabled)

//// Ghost calculator configs.

#endif // Ghost calculator.


//> Register native applications.
//>> Register Ghost system.
#if(1)
#define MacroGhostSystemInfo                                          MacroDeclareStructure(GhostAppInfo_t, GhostNativeApplication, "tech.h13.ghost", "Ghost System", 0, NULL, NULL)
#endif

//>> Register Ghost launcher.
#if(1)
#define MacroGhostLauncherPackageName                                 ("tech.h13.ghost.launcher")
#define MacroGhostLauncherInfo                                        MacroDeclareStructure(GhostAppInfo_t, GhostNativeApplication, "tech.h13.ghost.launcher", "Ghost Launcher", 0, GhostLauncherRun, NULL)
#define MacroGhostLauncherConfigFileName                              ("")

#endif //>> Ghost launcher.
