#include "GhostThemeHandle.h"

// Drivers.
#include "GhostMemoryManager.h"


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
GhostThemeHandle_t* GhostThemeMgrThemeHandleCreate(GhostTheme_t* ThemeInfo)
{
	GhostThemeHandle_t* handle = GhostMemMgrCalloc(1, sizeof(GhostThemeHandle_t));
	if (handle == NULL)
	{
		GhostLogE("Make theme handle failed, out of memory!");
		return NULL;
	}


	handle->ThemeInfo = *ThemeInfo;

	// Make a copy.
	/// Copy PackageName.
	int bufferSize = strlen(ThemeInfo->PackageName) + 1;
	handle->ThemeInfo.PackageName = GhostMemMgrMalloc(bufferSize);
	if (handle->ThemeInfo.PackageName == NULL)
	{
		GhostMemMgrFree(handle);
		GhostLogE("Make theme handle failed, out of memory!");
		return NULL;
	}

	memcpy(handle->ThemeInfo.PackageName, ThemeInfo->PackageName, bufferSize);

	/// Copy ThemeName.
	bufferSize = strlen(ThemeInfo->ThemeName) + 1;
	handle->ThemeInfo.ThemeName = GhostMemMgrMalloc(bufferSize);
	if (handle->ThemeInfo.ThemeName == NULL)
	{
		GhostMemMgrFree(handle->ThemeInfo.PackageName);
		GhostMemMgrFree(handle);
		GhostLogE("Make theme handle failed, out of memory!");
		return NULL;
	}

	memcpy(handle->ThemeInfo.ThemeName, ThemeInfo->ThemeName, bufferSize);
	return handle;
}


/// <summary>
/// Free memory of GhostThemeHandle_t.
/// 	Thread safe:
///			Yes.
/// </summary>
/// <param name="ThemeHandle">Theme handle.</param>
void GhostThemeHandleDestory(GhostThemeHandle_t* ThemeHandle)
{
	GhostMemMgrFree(ThemeHandle->ThemeInfo.PackageName);
	GhostMemMgrFree(ThemeHandle->ThemeInfo.ThemeName);
}


/// <summary>
/// Compare whether the theme handle are the same by package name.
/// </summary>
/// <param name="ThemeHandleA">Theme handle.</param>
/// <param name="ThemeHandleB">Theme handle.</param>
/// <returns>Return 1 when the package name is the same and not NULL.</returns>
int GhostThemeHandleMatch(GhostThemeHandle_t* ThemeHandleA, GhostThemeHandle_t* ThemeHandleB)
{
	// Simple check.
	if ((ThemeHandleA == NULL) || (ThemeHandleB == NULL) ||
		(ThemeHandleA->ThemeInfo.PackageName == NULL) ||
		(ThemeHandleB->ThemeInfo.PackageName == NULL))
	{
		return 0;
	}

	if (ThemeHandleA == ThemeHandleB)
	{
		return 1;
	}

	if (!strcmp(ThemeHandleA->ThemeInfo.PackageName, ThemeHandleB->ThemeInfo.PackageName))
	{
		return 1;
	}
	else {
		return 0;
	}
}

