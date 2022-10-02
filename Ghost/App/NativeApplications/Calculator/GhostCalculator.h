#pragma once
/*******************************************************************************
 * @File   : $safeitemname$.h
 * @Path   : $rootnamespace$/$safeitemname$.h
 * @Module : 
 * 
 * @Author : $username$
 * @Time   : $time$
 * @license: AGPL-3.0(https://github.com/h13-0/Ghost/blob/master/LICENSE)
 * @Notes  :
 *		This template file is only applicable to visual studio.
 * 
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"

// Standard headers.

// Ghost headers.
#include "GhostErrorDefine.h"
#include "GhostAppAPIs.h"

/***********************************Defines************************************/


/***********************************Typedefs***********************************/
EXTREN_C_START


/**********************************Prototypes**********************************/

/// <summary>
/// Entry function of Ghost Calculator.
/// </summary>
/// <param name="Param">Pointor of Arguments.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostCalculatorRun(const GhostAppArgs_t* Param);

EXTREN_C_END
