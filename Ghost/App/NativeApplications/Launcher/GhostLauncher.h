#pragma once

#include "GhostSoftwareErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// Entry function of Ghost Launcher.
	/// </summary>
	/// <param name="Args">Pointor of Arguments.</param>
	/// <returns></returns>
	GhostError_t GhostLauncherRun(void* Args);

#ifdef __cplusplus
}
#endif
