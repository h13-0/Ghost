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
GhostError_t GhostThreadCreate(GhostThread_t Thread, void* (*Function)(void*), const char* TaskName, size_t StackSize, void* Args, int Priority)
{
	// Create thread handle.
	Thread = malloc(sizeof(pthread_t));
	if (Thread == NULL)
		GhostErrorThreadOutOfMemory;

	// Create thread.
	if (!pthread_create(Thread, NULL, Function, Args))
		return GhostErrorThreadCreateFailed;

	return GhostOK;
}

/// <summary>
/// Force threads to stop and reclaim resources.
/// </summary>
/// <param name="Thread">Thread handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThreadDelete(GhostThread_t Thread)
{
	//pthread_cance
	return GhostOK;
}

/// <summary>
/// Create mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexCreate(GhostMutex_t Mutex)
{
	return GhostOK;
}

/// <summary>
/// Delete mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexDelete(GhostMutex_t Mutex)
{
	return GhostOK;
}

/// <summary>
/// Lock mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexLock(GhostMutex_t Mutex)
{
	return GhostOK;
}

/// <summary>
/// Unlock mutex.
/// </summary>
/// <param name="Mutex">Mutex handle.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMutexUnlock(GhostMutex_t Mutex)
{
	return GhostOK;
}
