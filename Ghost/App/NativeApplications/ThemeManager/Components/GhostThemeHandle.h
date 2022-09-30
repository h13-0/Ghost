// This file is a component of GhostThemeManager.
// Please do not call it in other files

// Standard libs.
#include <stdbool.h>

#include "GhostTheme.h"

#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// Typedef struct of GhostThemeHandle.
	/// </summary>
	typedef struct
	{
		// Basic theme info.
		GhostTheme_t ThemeInfo;

		// Resources.
		void* Resources;
		void** Blocks;

		// Theme status.
		bool ThemeLoaded : 1;
		bool MainPageLoaded : 1;
		bool StandbyPageLoaded : 1;
		bool AppDrawerPageLoaded : 1;
	} GhostThemeHandle_t;


	/// <summary>
	/// Generate GhostThemeHandle_t using theme info(GhostTheme_t).
	/// 	Thread safe:
	///			Yes.
	/// </summary>
	/// <param name="ThemeInfo">Theme info in pointor of GhostTheme_t.</param>
	/// <returns>
	/// Pointor of theme handle.
	///		Make fails when the return value is null.
	/// </returns>
	GhostThemeHandle_t* GhostThemeMgrThemeHandleCreate(GhostTheme_t* ThemeInfo);


	/// <summary>
	/// Free memory of GhostThemeHandle_t.
	/// 	Thread safe:
	///			Yes.
	/// </summary>
	/// <param name="ThemeHandle">Theme handle.</param>
	void GhostThemeHandleDestory(GhostThemeHandle_t* ThemeHandle);


	/// <summary>
	/// Compare whether the theme handle are the same by package name.
	/// </summary>
	/// <param name="ThemeHandleA">Theme handle.</param>
	/// <param name="ThemeHandleB">Theme handle.</param>
	/// <returns>Return 1 when the package name is the same.</returns>
	int GhostThemeHandleMatch(GhostThemeHandle_t* ThemeHandleA, GhostThemeHandle_t* ThemeHandleB);

#ifdef __cplusplus
}
#endif

