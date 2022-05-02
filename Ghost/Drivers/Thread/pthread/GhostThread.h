#pragma once

#include <stddef.h>
#include "pthread.h"

#include "GhostDriverErrorDefine.h"

// Define errors.
#define GhostErrorThreadCreateFailed       DeclareGhostError(GhostDriverLayerError, DriverModuleThreadError, 1)
#define GhostErrorThreadOutOfMemory        DeclareGhostError(GhostDriverLayerError, DriverModuleThreadError, 2)

#ifdef __cplusplus
extern "C" {
#endif

	/// <summary>
	/// Typedef of GhostThread_t.
	/// </summary>
	typedef pthread_t* GhostThread_t;
	
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
	GhostError_t GhostThreadCreate(GhostThread_t Thread, 
		void*(*Function)(void*), const char* TaskName, size_t StackSize, void *Args, int Priority);
	
	/// <summary>
	/// Force threads to stop and reclaim resources.
	/// </summary>
	/// <param name="Thread">Thread handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostThreadDelete(GhostThread_t Thread);

	/// <summary>
	/// Typedef of Ghost
	/// </summary>
	typedef pthread_mutex_t* GhostMutex_t;

	/// <summary>
	/// Create mutex.
	/// </summary>
	/// <param name="Mutex">Mutex handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostMutexCreate(GhostMutex_t Mutex);

	/// <summary>
	/// Delete mutex.
	/// </summary>
	/// <param name="Mutex">Mutex handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostMutexDelete(GhostMutex_t Mutex);

	/// <summary>
	/// Lock mutex.
	/// </summary>
	/// <param name="Mutex">Mutex handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostMutexLock(GhostMutex_t Mutex);

	/// <summary>
	/// Unlock mutex.
	/// </summary>
	/// <param name="Mutex">Mutex handle.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostMutexUnlock(GhostMutex_t Mutex);

#ifdef __cplusplus
}
#endif
