#pragma once
#include "GhostPlatformConfigs.h"
#if defined(MacroGhostThemeAppleInfograph)

#include "GhostTheme.h"

#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// Initialize theme common resource.
	///		This function will not initialize all other pages.
	/// </summary>
	/// <param name="void"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeAppleInfographInit(void);


	/// <summary>
	/// 
	/// </summary>
	/// <param name="MainPage"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThemeAppleInfographMainPageCreate(lv_obj_t* MainPage, void* ResourcePtr);

#ifdef __cplusplus
}
#endif

#endif //#if defined(MacroGhostThemeAppleInfograph)
