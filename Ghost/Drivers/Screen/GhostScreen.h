#pragma once

#include "GhostDriverErrorDefine.h"

#ifdef __cplusplus
extern "C" {
#endif
	
	/// <summary>
	/// Get screen resolution.
	/// </summary>
	/// <param name="Width">Width.</param>
	/// <param name="Height">Height.</param>
	/// <returns>Always GhostOK.</returns>
	GhostError_t GhostScreenGetResolution(int* Width, int* Height);

	
	/// <summary>
	/// Get screen fillet radius.
	/// </summary>
	/// <param name="Radius">Radius.</param>
	/// <returns>Always GhostOK.</returns>
	GhostError_t GhostScreenGetRadius(int* Radius);

	
#ifdef __cplusplus
}
#endif
