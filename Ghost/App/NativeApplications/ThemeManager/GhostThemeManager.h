#pragma once

#include "GhostSoftwareErrorDefine.h"

#define GhostErrorThemeMgrUninitialized                     DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 1)
#define GhostErrorThemeMgrThemeUninitialized                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 2)
#define GhostErrorThemeMgrThemeConfigFileMissing            DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 3)
#define GhostErrorThemeMgrThemeConfigIllegal                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 4)
#define GhostErrorThemeMgrThemeInitializationFailed         DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleThemeMgrError, 5)

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {
		// Basic informations.
		char* PackageName;
		char* ThemeName;
		int Version;
		
		// Function handles.
		// Init
		// Destory

		
		// 
	} GhostTheme_t;

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	GhostError_t GhostThemeMgrInit(void);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="PackageName"></param>
	/// <param name="Theme"></param>
	/// <returns></returns>
	GhostError_t GhostThemeMgrRegeisterTheme(char *PackageName, GhostTheme_t* Theme);


	GhostError_t GhostThemeMgrUnloadTheme(GhostTheme_t* Theme);
	
	
	
#ifdef __cplusplus
}
#endif
