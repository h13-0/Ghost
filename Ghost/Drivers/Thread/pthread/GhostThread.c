/*******************************************************************************
 * @File   : $safeitemname$
 * @Path   : $rootnamespace$
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
// Self headers.
#include "GhostThread.h"

// Standard headers.
#include <stdlib.h>
#include <stddef.h>

// ThirdParty headers.
#include "pthread.h"

// Ghost headers.


/***********************************Defines************************************/



/***********************************Typedefs***********************************/


/**********************************Prototypes**********************************/

/// <summary>
/// Initialize GhostThread module.
/// </summary>
/// <returns>Function execution result.</returns>
GhostError_t GhostThreadModuleInit()
{
	// Noting to do in pthread.
	return GhostOK;
}


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
	const char* TaskName, size_t StackSize, void* Args, int Priority) 
{
	if (!Function)
		return GhostThreadErrFunctionHandleIllegal;

	// Create thread.
	if (pthread_create(Thread, NULL, Function, Args))
		return GhostThreadErrCreateFailed;

	return GhostOK;
}

/// <summary>
/// Force threads to stop and reclaim resources.
/// </summary>
/// <param name="Thread">Thread handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThreadDelete(GhostThread_t* Thread)
{
	// TODO
	//pthread_cance
	return GhostOK;
}


/// <summary>
/// Get the number of threads created by GhostThread.
/// </summary>
/// <param name="void"></param>
/// <returns>Number of threads created by GhostThread.</returns>
int GhostThreadGetNumberOfThreads(void)
{
	return 0;
}


/// <summary>
/// Init mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexInit(GhostMutex_t* Mutex)
{
	if (pthread_mutex_init(Mutex, NULL))
	{
		return GhostMutexErrCreateFailed;
	}
		
	return GhostOK;
}

/// <summary>
/// Destroy mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexDestroy(GhostMutex_t* Mutex)
{
#if(MacroGhostDebug)
	// Check handle.
	if (Mutex == NULL)
	{
		return GhostMutexErrUninitialized;
	}
#endif

	if (pthread_mutex_destroy(Mutex))
		return GhostMutexErrDestroyFailed;

	return GhostOK;
}


/// <summary>
/// Lock mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexLock(GhostMutex_t* Mutex)
{
#if(MacroGhostDebug)
	// Check handle.
	if (Mutex == NULL)
	{
		return GhostMutexErrUninitialized;
	}
#endif

	// Lock mutex.
	if (pthread_mutex_lock(Mutex))
	{
		return GhostMutexErrLockFailed;
	}
	else {
		return GhostOK;
	}
}

/// <summary>
/// Unlock mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexUnlock(GhostMutex_t* Mutex)
{
#if(MacroGhostDebug)
	// Check handle.
	if (Mutex == NULL)
	{
		return GhostMutexErrUninitialized;
	}
#endif

	// Unlock mutex.
	if (pthread_mutex_unlock(Mutex))
	{
		return GhostMutexErrUnlockFailed;
	}
	else {
		return GhostOK;
	}
}


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
GhostError_t GhostMutexTryLock(GhostMutex_t* Mutex)
{
#if(MacroGhostDebug)
	// Check handle.
	if (Mutex == NULL)
	{
		return GhostMutexErrUninitialized;
	}
#endif

	// Try lock mutex.
	if (pthread_mutex_trylock(Mutex))
	{
		return GhostMutexErrLockFailed;
	}
	else {
		return GhostOK;
	}
}
