#pragma once

#include "GhostSoftwareErrorDefine.h"

#define GhostErrorLauncherMgrUninitialized                     DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleLauncherError, 1)
#define GhostErrorLauncherMgrAlreadyInitialized                DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleLauncherError, 2)
#define GhostErrorLauncherMgrOutOfMemory                       DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleLauncherError, 3)

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
