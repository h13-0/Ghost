#include "GhostThread.h"

#include <stdlib.h>
#include <stddef.h>

#include "pthread.h"

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
GhostError_t GhostThreadCreate(GhostThread_t* Thread, void* (*Function)(void*), const char* TaskName, size_t StackSize, void* Args, int Priority)
{
	if (!Function)
		return GhostErrorFunctionHandleIllegal;

	// Create thread.
	if (pthread_create(Thread, NULL, Function, Args))
		return GhostErrorThreadCreateFailed;

	return GhostOK;
}

/// <summary>
/// Force threads to stop and reclaim resources.
/// </summary>
/// <param name="Thread">Thread handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThreadDelete(GhostThread_t* Thread)
{
	//pthread_cance
	return GhostOK;
}

/// <summary>
/// Init mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexInit(GhostMutex_t* Mutex)
{
	if (pthread_mutex_init(Mutex, NULL))
		return GhostErrorMutexCreateFaild;

	return GhostOK;
}

/// <summary>
/// Destroy mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexDestroy(GhostMutex_t* Mutex)
{
#ifdef DEBUG
	// Check handle.
	if (Mutex == NULL)
		return GhostErrorMutexUninitialized;
#endif

	if (pthread_mutex_destroy(Mutex))
		return GhostErrorMutexDeleteFailed;

	return GhostOK;
}

/// <summary>
/// Lock mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexLock(GhostMutex_t* Mutex)
{
#ifdef DEBUG
	// Check handle.
	if (Mutex == NULL)
		return GhostErrorMutexUninitialized;
#endif

	// Lock mutex.
	if (pthread_mutex_lock(Mutex))
		return GhostErrorMutexLockFailed;
	return GhostOK;
}

/// <summary>
/// Unlock mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexUnlock(GhostMutex_t* Mutex)
{
#ifdef _DEBUG
	// Check handle.
	if (Mutex == NULL)
		return GhostErrorMutexUninitialized;
#endif

	// Unlock mutex.
	if (pthread_mutex_unlock(Mutex))
		return GhostErrorMutexLockFailed;
	return GhostOK;
}
