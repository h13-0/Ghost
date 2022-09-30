#pragma once
/*******************************************************************************
 * @File   : $safeitemname$.c
 * @Path   : $rootnamespace$/$safeitemname$.c
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

/***********************************Defines************************************/


/***********************************Typedefs***********************************/
EXTREN_C_START


/// <summary>
/// Pair of app resource, binding pointer and destructor.
/// </summary>
typedef struct
{
	void* Resource;
	void(*Free)(void*);
} GhostAppResPair_t;


/// <summary>
/// 
/// </summary>
typedef struct GhostAppResPool
{
	int Capacity;
	int AppResNum;
	GhostAppResPair_t* Pool;
};
typedef struct GhostAppResPool* GhostAppResPool_t;


/// <summary>
/// 
/// </summary>
/// <param name="InitialCapactiy"></param>
/// <returns></returns>
GhostAppResPool_t GhostAppResPoolNew(int InitialCapactiy);



/**********************************Prototypes**********************************/

/// <summary>
/// Some function.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
// int func(void);




EXTREN_C_END
