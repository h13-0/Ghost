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
 *		The pthread implementation of Ghost Thread.
 *
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"

// Standard headers.
#include <stddef.h>

// ThirdParty headers.
#include "pthread.h"

// Ghost headers.
#include "GhostDriverErrorDefine.h"

/***********************************Defines************************************/
// Define errors.
//> Thread errors.
#define DeclareGhostThreadErrCode(ID) \
	DeclareGhostError(GhostDriverLayerError, DriverModuleThreadError, ID)
#define GhostThreadErrOutOfMemory					DeclareGhostThreadErrCode(1)
#define GhostThreadErrCreateFailed					DeclareGhostThreadErrCode(2)
#define GhostThreadErrFunctionHandleIllegal			DeclareGhostThreadErrCode(3)

//> Mutex errors.
#define DeclareGhostMutexErrCode(ID) \
	DeclareGhostError(GhostDriverLayerError, DriverModuleMutexError, ID)
#define GhostMutexErrOutOfMemory					DeclareGhostMutexErrCode(1)
#define GhostMutexErrCreateFailed					DeclareGhostMutexErrCode(2)
#define GhostMutexErrUninitialized					DeclareGhostMutexErrCode(3)
#define GhostMutexErrLockFailed						DeclareGhostMutexErrCode(4)
#define GhostMutexErrUnlockFailed					DeclareGhostMutexErrCode(5)
#define GhostMutexErrDestroyFailed					DeclareGhostMutexErrCode(6)

/***********************************Typedefs***********************************/
#ifdef __cplusplus
EXTREN_C_START
#endif // __cplusplus


/// <summary>
/// Typedef of GhostThread_t.
/// </summary>
typedef pthread_t GhostThread_t;


/// <summary>
/// Typedef of Ghost
/// </summary>
typedef pthread_mutex_t GhostMutex_t;


/**********************************Prototypes**********************************/

/// <summary>
/// Initialize GhostThread module.
/// </summary>
/// <returns>Function execution result.</returns>
GhostError_t GhostThreadModuleInit();


/// <summary>
/// Create thread.
/// </summary>
/// <param name="Thread">Thread handle.</param>
/// <param name="Function">Function executed by thread.</param>
/// <param name="TaskName">Task name, invalid in pthread.</param>
/// <param name="StackSize">StackSize, default if 0.</param>
/// <param name="Args">Args.</param>
/// <param name="Priority">Priority, invalid in pthread.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThreadCreate(GhostThread_t* Thread, void* (*Function)(void*), 
	const char* TaskName, size_t StackSize, void* Args, int Priority);


/// <summary>
/// Force threads to stop and reclaim resources.
/// </summary>
/// <param name="Thread">Thread handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThreadDelete(GhostThread_t* Thread);


/// <summary>
/// Get the number of threads created by GhostThread.
/// </summary>
/// <param name="void"></param>
/// <returns>Number of threads created by GhostThread.</returns>
int GhostThreadGetNumberOfThreads(void);


/// <summary>
/// Init mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexInit(GhostMutex_t* Mutex);


/// <summary>
/// Destroy mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexDestroy(GhostMutex_t* Mutex);


/// <summary>
/// Lock mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexLock(GhostMutex_t* Mutex);


/// <summary>
/// Unlock mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexUnlock(GhostMutex_t* Mutex);


/// <summary>
/// Try lock mutex.
/// `GhostMutexTryLock` function locks the spin lock referenced by lock if it 
///		is not held by any thread. Otherwise, the function fails.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>
/// `GhostOK` is returned when mutex is successfully locked.
/// Otherwise, return `GhostMutexErrLockFailed` or `GhostMutexErrUninitialized`.
/// </returns>
GhostError_t GhostMutexTryLock(GhostMutex_t* Mutex);

#ifdef __cplusplus
EXTREN_C_END
#endif // __cplusplus
