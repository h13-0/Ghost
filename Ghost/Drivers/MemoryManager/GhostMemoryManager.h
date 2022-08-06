#pragma once

#include "GhostDriverErrorDefine.h"

#include <stdbool.h>

#define GhostErrorMemMgrUninitialized                     DeclareGhostError(GhostDriverLayerError, DriverModuleMemoryManagerError, 1)
#define GhostErrorMemMgrAlreadyInitialized                DeclareGhostError(GhostDriverLayerError, DriverModuleMemoryManagerError, 2)
#define GhostErrorMemMgrOutOfMemory                       DeclareGhostError(GhostDriverLayerError, DriverModuleMemoryManagerError, 3)


#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// Init Ghost memory manager.
	///		Dependent modules:
	///			GhostThread
	///		Thread safe:
	///			NO.
	/// </summary>
	/// <param name="MaximumMemoryUsageLimit">Maximum memory usage.</param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostMemMgrInit(size_t MaximumMemoryUsageLimit);


	/// <summary>
	/// Set log enable status.
	///		It needs to be used after `GhostLogInit`.
	///		Thread safe:
	///			Yes.
	/// </summary>
	/// <param name="Status">Ture to enable, deafult is false.</param>
	/// <returns></returns>
	GhostError_t GhostMemMgrSetLogEnableStatus(bool Status);


	/// <summary>
	/// Get the total memory size allocated through GhostMemoryManager.
	/// </summary>
	/// <param name="void"></param>
	/// <returns>Total memory usage.</returns>
	size_t GhostMemMgrGetMemUsage(void);
	

	/// <summary>
	/// Get the peak total memory size allocated through GhostMemoryManager.
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	size_t GhostMemMgrGetPeakMemUsage(void);


	/// <summary>
	/// Rewrite or encapsulate memory management functions in C standard library.
	///		Thread safe:
	///			Yes.
	/// </summary>
	/// <param>The parameters are the same as those of C standard library.</param>
	/// <returns>The return values are the same as those of C standard library.</returns>
	void* GhostMemMgrMalloc(size_t Size);
	void* GhostMemMgrCalloc(size_t Count, size_t Size);


	/// <summary>
	/// Packaging of realloc, and the behavior is the same as `realloc`.
	/// @Thread safe:
	///			Yes.
	/// @Reference:
	///		Quoted from the lastest draft `N1570` of `ISO/IEC 9899:2011`:
	///			If ptr is a null pointer, the realloc function behaves like the malloc function for the specified size.
	///			Otherwise, if ptr does not match a pointer earlier returned by a memory management function,
	///			or if the space has been deallocated by a call to the free or realloc function, 
	///			the behavior is undefined.If memory for the new object cannot  be allocated, 
	///			the old object is not deallocated and its value is unchanged.
	/// </summary>
	/// <param name="Ptr">
	/// Pointer to the memory area to be reallocated.
	///		If Ptr == NULL, the behavior is the same as calling `GhostMemMgrMalloc`.
	/// </param>
	/// <param name="NewSize">
	/// New size of the array in bytes.
	///		If NewSize == 0, the behavior is the same as calling `GhostMemMgrFree`.
	/// </param>
	/// <returns>
	/// @Reference:
	///		Quoted from the lastest draft `N1570` of `ISO/IEC 9899:2011`:
	///			The realloc function returns a pointer to the new object (which may have the same value as a pointer to the old object),
	///			or a null pointer if the new object could not be allocated.
	/// </returns>
	void* GhostMenMgrRealloc(void* Ptr, size_t NewSize);


	/// <summary>
	/// Packaging of free, and the behavior is the same as `free`.
	/// @Thread safe:
	///			Yes.
	/// @Reference:
	/// 	Quoted from the lastest draft `N1570` of `ISO/IEC 9899:2011`:
	///			The free function causes the space pointed to by ptr to be deallocated, that is,
	///			made available for further allocation.If ptr is a null pointer, no action occurs.
	///			Otherwise, if the argument does not match a pointer earlier returned by a memory management	function,
	///			or if the space has been deallocated by a call to free or realloc, the behavior is undefined.
	/// </summary>
	/// <param name="Ptr">
	/// Pointer to the memory to deallocate.
	/// </param>
	void GhostMemMgrFree(void* Ptr);


	/// <summary>
	/// Gets the size allocated by GhostMemoryManager.
	/// </summary>
	/// <param name="Ptr">
	/// Pointer to the memory to deallocate.
	/// </param>
	/// <returns>
	/// Size of allocated memory.
	/// </returns>
	size_t GhostMemMgrGetPointorSize(void* Ptr);

	/// <summary>
	/// Destory GhostMemoryManager.
	/// </summary>
	/// <param name="void"></param>
	/// <returns>Function execution result.</returns>
	GhostError_t GhostMenMgrDestory(void);

#ifdef __cplusplus
}
#endif


