#pragma once
#include "DeclareStructure.h"

/******************************************************* Ghost compiler configs *******************************************************/
#define MacroStatic                                                   static
#define MacroInline                                                   inline
#define MacroStaticInline                                             static inline


/****************************************************** Ghost common declarations *****************************************************/
#define MacroGhostMemOptStrict                                        (1)
#define MacroGhostMemOptNormal                                        (2)
#define MacroGhostMemOptExperience                                    (3)

#define MacroGhostSizeOptStrict                                       (1)
#define MacroGhostSizeOptNormal                                       (2)
#define MacroGhostSizeOptExperience                                   (3)

// Debug Ghost.
#ifdef DEBUG
#define MacroGhostDebug                                               (1)
#else // DEBUG
#define MacroGhostDebug                                               (1)
#endif // DEBUG


/******************************************************* Ghost platform configs *******************************************************/
//> Virtual Screen configs.
#define MacroDynamicScreenResolution                                  (1) //Used when using qtsimulator for UI development.

#if(MacroDynamicScreenResolution)

//#define MacroDisplayHorizontalResolution                              GhostScreenGetWidth()
//#define MacroDisplayVerticalResolution                                GhostScreenGetHeight()

//> Qt simulator configs.
#define MacroQtMaximumHorizontalResolution                            (1080)
#define MacroQtMaximumVerticalResolution                              (1080)
#define MacroQtDefaultFilletRadius                                    (10)
#else
#define MacroDisplayHorizontalResolution                              (240)
#define MacroDisplayVerticalResolution                                (240)
#endif

/******************************************************** Ghost driver configs ********************************************************/
//> Memory manager.
#define MacroMaximumMemoryUsageLimit                                  (4096 * 1024) // 4096 * 1024Bytes.
#define GhostPointor_t                                                ()
#if defined(_WIN32)
//> It's windows.
#if defined(_WIN64)
//>> Windows x64
#define MacroEffectiveLengthOfPointer                                 (64)          // Reasonable pointer effective length can reduce memory consumption.
#else
//>> Windows x86
#define MacroEffectiveLengthOfPointer                                 (32)          // Reasonable pointer effective length can reduce memory consumption.
#endif

#elif defined(__linux__)  // Is unix
//> It's unix.
#if defined(__x86_64__)
//>> Linux x64.
#define MacroEffectiveLengthOfPointer                                 (64)          // Reasonable pointer effective length can reduce memory consumption.
#else
//>> Linux x86.
#define MacroEffectiveLengthOfPointer                                 (32)          // Reasonable pointer effective length can reduce memory consumption.
#endif
#else
//> Unknown system.
//>> Manually set pointer effective length.
#define MacroEffectiveLengthOfPointer                                 (16)          // Reasonable pointer effective length can reduce memory consumption.
#endif

//> File system configs.
#define MacroFileSystemMountPoint                                     ("./Ghost")   //**Paths should be separated by '/'**
#define MacroMaximumPathLength                                        (256)


//> Screen configs.
#define MacroScreenRefreshRate                                        (60)

/********************************************************* Ghost app configs **********************************************************/
//> Ghost system configs.
#if(1)
#define MacroSystemName                                               ("Ghost")
#define MacroSystemVersion                                            ("")         // TODO: Reference cmake version number.

//>> Memory optimization.
#define MacroGhostSystemMemOptimizeLevel                              (MacroGhostMemOptExperience)
#define MacroGhostSystemSizeOptimizeLevel                             (MacroGhostSizeOptExperience)

#endif // Ghost system configs.

//> Ghost component configs
#if(1)
//>> GhostAppFramework
#define MacroMaximumAppPackageNameLength                              (64)
#define MacroMaximumAppNameLength                                     (16)


#endif

//> Ghost user configs.
#if(1)
#define MacroAllowRoot                                                (1)
#define MacroWhoAmI                                                   ("h13")
#endif // Ghost user configs.


//> Ghost components configs.
//>> Ghost log configs.
#if(1)
#define MacroGhostLogMaximumContentsSize                              (256)
#define MacroGhostLogMinimumLogLevel                                  (Debug)

// Output functions.
#include "QtSimulator.h"
#define MacroGhostLogOutputFunctions                                  { }

// Output files.
#define MacroGhostLogOutputFiles                                      { stdout }

#if defined(_DEBUG)
#define MacroGhostLogOutputFileName                                   (1)
#define MacroGhostLogOutputLineNumber                                 (1)

#else // #if defined(_DEBUG)
#warn "TODO"
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
#define MacroGhostAppDefaultResPoolCapacity							  (16)

//> Ghost theme manager.
//>>> Built-in themes.


// TODO: Register themes instead of declaring themes.
#define MacroGhostThemeSafeTheme                                      () //The theme of security mode must be very stable and lightweight.


#define MacroGhostThemeAppleInfograph                                 ("tech.h13.ghost.theme.appleinfograph")
#if defined(MacroGhostThemeAppleInfograph)

#define MacroGhostThemeAppleInfographName                             ("Apple Infograph")
#define MacroGhostThemeAppleInfographVersion                          (1)
#define MacroGhostThemeAppleInfographInitFunction                     GhostThemeAppleInfographInit
#define MacroGhostThemeAppleInfographDestoryFunction                  (NULL)
#define MacroGhostThemeAppleInfographMainPageCreateFunction           GhostThemeAppleInfographMainPageCreate
#define MacroGhostThemeAppleInfographMainPageRefreshFunction          GhostThemeAppleInfographMainPageRefresh
#define MacroGhostThemeAppleInfographAppDrawerPageCreateFunction      GhostThemeAppleInfographAppDrawerPageCreate

#endif //#if defined(MacroGhostLauncherThemeAppleInfograph)

#define MacroGhostLauncherThemeCunstomBackground                      ()


#define MacroGhostLauncherBuiltInThemes                               ()


//> Ghost launcher configs.
//>> Default theme.
//>> Select theme by package name.
#define MacroGhostLauncherDefaultTheme                                (MacroGhostThemeAppleInfograph)
//>> Advanced configs.
#define MacroGhostLauncherMemOptimizeLevel                            (MacroGhostSystemMemOptimizeLevel)

//>> Ghost calculator.
#define MacroIsCalculatorEnabled                                      (1)
#if(MacroIsCalculatorEnabled)

//// Ghost calculator configs.

#endif // Ghost calculator.


//> Native applications.
//>> Ghost system.
#if(1)
#define MacroGhostSystemInfo									       MacroDeclareStructure(GhostAppInfo_t, GhostNativeApplication, "tech.h13.ghost", "Ghost System", 0, NULL, NULL)
#endif

//>> Ghost app framework.
#define MacroGhostAppFrmUseTokenOffset									(1)

//>> Ghost theme manager.
#if(1)
#define MacroGhostThemeManagerPackageName								("tech.h13.ghost.thememanager")
#define MacroGhostThemeManagerInfo										GhostAppFrmAppInfoNew( \
                                                                            GhostAppTypeNative, \
																			MacroGhostThemeManagerPackageName, \
																			"Theme manager", \
																			NULL, \
																			0, \
																			GhostThemeMgrRun, \
																			NULL \
																		)
#define MacroGhostThemeManagerConfigFileName							("")

// Refresh frame rate limit.
#define MacroGhostThemeManagerMainPageMinimumRefreshPeriod              (1000 / MacroScreenRefreshRate)


// Default frame rate.
#define MacroGhostThemeManagerMainPageDefaultRefreshPeriod              (1000 / 2)

#endif

//>> Ghost launcher.
#if(1)
#define MacroGhostLauncherPackageName									("tech.h13.ghost.launcher")
#define MacroGhostLauncherInfo											GhostAppFrmAppInfoNew( \
                                                                            GhostAppTypeNative, \
																			MacroGhostLauncherPackageName, \
																			"Ghost Launcher", \
                                                                            NULL, \
																			0, \
																			GhostLauncherRun, \
																			NULL \
																		)
#define MacroGhostLauncherConfigFileName								("")

#endif //>> Ghost launcher.


//>> Ghost calculator.
#if(MacroIsCalculatorEnabled)
#define MacroGhostCalculatorPackageName									("tech.h13.ghost.calculator")
#define MacroGhostCalculatorInfo										GhostAppInfoNew( \
																			GhostAppTypeNative, \
																			MacroGhostCalculatorPackageName, \
																			"Calculator", \
																			NULL, \
																			0, \
																			GhostCalculatorRun, \
																			NULL \
																		)


#endif //>> Ghost calculator.

// Let Visual studio not indent extren "C"
#define EXTREN_C_START extern "C" {
#define EXTREN_C_END   }
