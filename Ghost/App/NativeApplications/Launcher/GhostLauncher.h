#pragma once

#include "GhostSoftwareErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// Entry function of Ghost Launcher.
	/// </summary>
	/// <param name="Argc">Arguments' count.</param>
	/// <param name="Args">Pointor of Arguments.</param>
	/// <returns></returns>
	GhostError_t GhostLauncherRun(int Argc, void** Args);

#ifdef __cplusplus
}
#endif
