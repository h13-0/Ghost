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
 * 
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"

// Standard headers.

// Ghost headers.
#include "GhostSoftwareErrorDefine.h"
#include "GhostThread.h"

/***********************************Defines************************************/
// Define errors.
#define DeclareGhostAppResPoolErrCode(ID) \
	DeclareGhostError(GhostSoftwareLayerError, SoftwareModuleAppResPoolError, ID)
#define GhostAppResPoolErrOutOfMemory			DeclareGhostAppResPoolErrCode(1)
#define GhostAppResPoolErrCreateFailed			DeclareGhostAppResPoolErrCode(2)
#define GhostAppResPoolErrUninitialized			DeclareGhostAppResPoolErrCode(3)
#define GhostAppResPoolErrDestroyFailed			DeclareGhostAppResPoolErrCode(4)
#define GhostAppResPoolErrParamIllegal			DeclareGhostAppResPoolErrCode(5)
#define GhostAppResPoolErrResNotFound			DeclareGhostAppResPoolErrCode(6)

/***********************************Typedefs***********************************/
#ifdef __cplusplus
EXTREN_C_START
#endif // __cplusplus


/// <summary>
/// Typedef of App resource pool.
/// </summary>
typedef void* GhostAppResPool_t;


/**********************************Prototypes**********************************/

/// <summary>
/// Create a resource pool of the specified initial size.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="InitialCapactiy">
/// Initial resource pool size.
/// When the resource pool is full, the capacity will be multiplied by 2.
/// </param>
/// <returns>
/// Resource pool pointer.
/// Returns NULL when create failed(out of memory).
/// </returns>
GhostAppResPool_t GhostAppResPoolNew(int InitialCapactiy);


/// <summary>
/// Destroy all elements in ResPool and free memory.
/// Elements will be released in reverse order.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppResPoolFree(GhostAppResPool_t ResPool);


/// <summary>
/// Resize ResPool capacity to specified size(if possible).
/// This function can be used to expand and narrow the resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="Pool">Resource pool pointer.</param>
/// <param name="Capacity">Target capacity.</param>
/// <returns>Capacity of ResPool after resized.</returns>
int GhostAppResPoolResize(GhostAppResPool_t ResPool, int Capacity);


/// <summary>
/// Register a resource item to ResPool.
/// This function keeps the order of the original items.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <param name="Resource">Resource pointor.</param>
/// <param name="Destroyer">Resource destroyer.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppResPoolAddItem(GhostAppResPool_t ResPool,
	void* Resource, void(*Destroyer)(void*));


/// <summary>
/// Destory a resource.
/// This function keeps the order of the original items.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <param name="Resource">Resource pointor.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppResPoolFreeItem(GhostAppResPool_t ResPool, void* Resource);


#ifdef __cplusplus
EXTREN_C_END
#endif // __cplusplus
