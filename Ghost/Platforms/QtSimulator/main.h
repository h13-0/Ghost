#pragma once
#include "GhostPlatformConfigs.h"

#if(MacroDynamicScreenResolution)
#include "lvgl.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if(MacroDynamicScreenResolution)

	/// <summary>
	/// Get the resolution of Qt Simulator.
	/// </summary>
	/// <note>
	/// This function **DOSE NOT** need to be ported under normal circumstances.
	/// Generally, you only need to define the constant `MacroDisplayHorizontalResolution` and `MacroDisplayVerticalResolution` in the `GhostPlatformConfigs.h` file.
	/// In the QtSimulator, `MacroDisplayHorizontalResolution` and `MacroDisplayVerticalResolution` is defined as the following two functions in the `GhostPlatformConfigs.h` file.
	/// </note>
	/// <returns>Resolution.</returns>
	lv_coord_t GhostQtSimulatorGetHorizontalResolution(void);

	lv_coord_t GhostQtSimulatorGetVerticalResolution(void);
#endif

#ifdef __cplusplus
}
#endif
