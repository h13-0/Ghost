#pragma once

#include "GhostSoftwareErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {
		// Basic informations.
		char* PackageName;
		char* ThemeName;
		int Version;
		
		// Function handles.
		
		
		// 
	} Theme_t;

	GhostError_t GhostThemeMgrInit(void);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="PackageName">Default theme when null.</param>
	/// <param name="Theme"></param>
	/// <returns></returns>
	GhostError_t GhostThemeMgrLoadTheme(char *PackageName, Theme_t *Theme);

	GhostError_t GhostThemeMgrUnloadTheme(Theme_t* Theme);
	
	
	
#ifdef __cplusplus
}
#endif