#include "GhostMemoryManager.h"
#include "GhostPlatformConfigs.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "GhostThread.h"
#include "../Log/GhostLog.h"

#if(MacroMaximumMemoryUsageLimit <= 255)
typedef uint8_t __ghostMemSize_t;
#elif(MacroMaximumMemoryUsageLimit <= 65535)
typedef uint16_t __ghostMemSize_t;
#elif(MacroMaximumMemoryUsageLimit <= 4294967296)
typedef uint32_t __ghostMemSize_t;
#else
typedef uint64_t __ghostMemSize_t;
#endif


/// <summary>
/// Typedef of GhostMemMgrStatus_t.
/// </summary>
typedef struct
{
	// 
	GhostMutex_t Mutex;
	bool LogEnabled;

	// 
	__ghostMemSize_t TotalMemoryUsage;
	__ghostMemSize_t MaximumTotalMemortUsage;
	__ghostMemSize_t MaximumMemoryUsageLimit;

	// The size of the header of the record size that needs additional allocation.
	size_t SizeOfHeader;

	// Number of all memory blocks allocated.
	uint32_t MemoryBlocksNums;
	
	// TODO: Record all block addresses.
	//void** MemoryBlocks;
} GhostMemMgrStatus_t;


static GhostMemMgrStatus_t* status = NULL;


/// <summary>
/// Init Ghost memory manager.
///		Dependent modules:
///			GhostThread
///		Thread safe:
///			NO.
/// </summary>
/// <param name="MaximumMemoryUsageLimit">Maximum memory usage.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMemMgrInit(size_t MaximumMemoryUsageLimit)
{
	if (MaximumMemoryUsageLimit < sizeof(GhostMemMgrStatus_t))
	{
		return GhostErrorMemMgrOutOfMemory;
	}

	if (status)
	{
		return GhostErrorMemMgrAlreadyInitialized;
	}

	status = malloc(sizeof(GhostMemMgrStatus_t));
	if (!status)
	{
		return GhostErrorMemMgrOutOfMemory;
	}

	GhostTerminateIfErr(GhostMutexInit(&status->Mutex));

	GhostMutexLock(&status->Mutex);
	status->MaximumMemoryUsageLimit = MaximumMemoryUsageLimit;
	status->TotalMemoryUsage = sizeof(GhostMemMgrStatus_t);
	status->MaximumTotalMemortUsage = status->TotalMemoryUsage;
	status->SizeOfHeader = sizeof(__ghostMemSize_t);
	status->MemoryBlocksNums = 0;
	status->LogEnabled = false;
	GhostMutexUnlock(&status->Mutex);

	return GhostOK;
}


/// <summary>
/// Set log enable status.
///		It needs to be used after `GhostLogInit`.
///		Thread safe:
///			Yes.
/// </summary>
/// <param name="Status">Ture to enable, deafult is false.</param>
/// <returns></returns>
GhostError_t GhostMemMgrSetLogEnableStatus(bool Status)
{
	if (status)
	{
		GhostMutexLock(&status->Mutex);
		status->LogEnabled = Status;
		GhostMutexUnlock(&status->Mutex);
		return GhostOK;
	}
	else {
		return GhostErrorLogUninitialized;
	}
}


/// <summary>
/// Get the total memory size allocated through GhostMemoryManager.
/// </summary>
/// <param name="void"></param>
/// <returns>Total memory usage.</returns>
size_t GhostMemMgrGetMemUsage(void)
{
	size_t usage = 0;
	GhostMutexLock(&status->Mutex);
	usage = status->TotalMemoryUsage;
	GhostMutexUnlock(&status->Mutex);
	return usage;
}


/// <summary>
/// Get the peak total memory size allocated through GhostMemoryManager.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
size_t GhostMemMgrGetPeakMemUsage(void)
{
	size_t usage = 0;
	GhostMutexLock(&status->Mutex);
	usage = status->MaximumTotalMemortUsage;
	GhostMutexUnlock(&status->Mutex);
	return usage;
}


/// <summary>
/// Rewrite or encapsulate memory management functions in C standard library.
///		Thread safe:
///			Yes.
/// </summary>
/// <param>The parameters are the same as those of C standard library.</param>
/// <returns>The return values are the same as those of C standard library.</returns>
void* GhostMemMgrMalloc(size_t Size)
{
	void* ptr = NULL;
	Size += status->SizeOfHeader;
	GhostMutexLock(&status->Mutex);
	if (status->TotalMemoryUsage + Size <= status->MaximumMemoryUsageLimit)
	{
		ptr = malloc(Size);
		if (ptr)
		{
			status->TotalMemoryUsage += Size;
			if (status->TotalMemoryUsage > status->MaximumTotalMemortUsage)
			{
				status->MaximumTotalMemortUsage = status->TotalMemoryUsage;
			}
			status->MemoryBlocksNums++;
			memcpy(ptr, &(__ghostMemSize_t)(Size), status->SizeOfHeader);
			ptr = (size_t)ptr + status->SizeOfHeader;
		}
	}
	if (!ptr && status->LogEnabled)
	{
		GhostLogE("Out of memory.");
	}

	GhostMutexUnlock(&status->Mutex);
	return ptr;
}


void* GhostMemMgrCalloc(size_t Count, size_t Size)
{
	void* ptr = NULL;
	Size = Count * Size + status->SizeOfHeader;
	GhostMutexLock(&status->Mutex);
	if (status->TotalMemoryUsage + Size <= status->MaximumMemoryUsageLimit)
	{
		ptr = calloc(1, Size);
		if (ptr)
		{
			status->TotalMemoryUsage += Size;
			if (status->TotalMemoryUsage > status->MaximumTotalMemortUsage)
			{
				status->MaximumTotalMemortUsage = status->TotalMemoryUsage;
			}
			status->MemoryBlocksNums++;
			memcpy(ptr, &(__ghostMemSize_t)(Size), status->SizeOfHeader);
			ptr = (size_t)ptr + status->SizeOfHeader;
		}
	}
	if (!ptr && status->LogEnabled)
	{
		GhostLogE("Out of memory.");
	}

	GhostMutexUnlock(&status->Mutex);
	return ptr;
}


/// <summary>
/// Packaging of realloc, and the behavior is the same as `realloc`.
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
void* GhostMenMgrRealloc(void* Ptr, size_t NewSize)
{
	if (Ptr && NewSize)
	{
		// If Ptr != NULL and Size != 0, execute normally.
		
		// Get basic information of pointer.
		void* newPtr = NULL;
		void* realPtr = (void*)((size_t)(Ptr) - status->SizeOfHeader);
		__ghostMemSize_t originalSize = 0;
		NewSize += status->SizeOfHeader;
		memcpy(&originalSize, realPtr, status->SizeOfHeader);

		// Execute realloc.
		GhostMutexLock(&status->Mutex);

		// Verify memory size.
		if ((originalSize > NewSize) ||
			((originalSize < NewSize) && (status->TotalMemoryUsage + NewSize - originalSize < status->MaximumMemoryUsageLimit)))
		{
			// Try to realloc.
			newPtr = realloc(realPtr, NewSize);
		}

		// Check whether the execution is successful.
		if (newPtr)
		{
			// realloc successful.
			status->TotalMemoryUsage = status->TotalMemoryUsage + NewSize - originalSize;
			if (status->TotalMemoryUsage > status->MaximumTotalMemortUsage)
			{
				status->MaximumTotalMemortUsage = status->TotalMemoryUsage;
			}
			memcpy(newPtr, &(__ghostMemSize_t)(NewSize), status->SizeOfHeader);
			newPtr = (void*)((size_t)newPtr + status->SizeOfHeader);
		}
		else {
			// realloc failed.
			if (status->LogEnabled)
			{
				GhostLogE("Out of memory.");
			}
		}

		GhostMutexUnlock(&status->Mutex);
		return newPtr;
	}
	else if (Ptr) {
		// Size == 0, use `GhostMemMgrFree`.
		GhostMemMgrFree(Ptr);
		return NULL;
	}
	else {
		// If Ptr == NULL, use `GhostMemMgrMalloc`.
		return GhostMemMgrMalloc(NewSize);
	}
}


/// <summary>
/// Packaging of free, and the behavior is the same as `free`.
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
void GhostMemMgrFree(void* Ptr)
{
	if (!Ptr)
	{
		return;
	}

	// Get basic information of pointer.
	void* realPtr = (void*)((size_t)(Ptr)-status->SizeOfHeader);
	__ghostMemSize_t originalSize = 0;
	memcpy(&originalSize, realPtr, status->SizeOfHeader);

	// Execute free.
	GhostMutexLock(&status->Mutex);
	free(realPtr);
	status->TotalMemoryUsage = status->TotalMemoryUsage - originalSize;
	status->MemoryBlocksNums--;
	GhostMutexUnlock(&status->Mutex);
}


/// <summary>
/// Gets the size allocated by GhostMemoryManager.
/// </summary>
/// <param name="Ptr">
/// Pointer to the memory to deallocate.
/// </param>
/// <returns>
/// Size of allocated memory.
/// </returns>
size_t GhostMemMgrGetPointorSize(void* Ptr)
{
	__ghostMemSize_t originalSize = 0;
	memcpy(&originalSize, (void*)((size_t)Ptr - sizeof(__ghostMemSize_t)), status->SizeOfHeader);
	originalSize -= sizeof(__ghostMemSize_t);
	return originalSize;
}


/// <summary>
/// Destory GhostMemoryManager.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostMenMgrDestory(void)
{
	if (status)
	{
		if (status->LogEnabled)
		{
			if (status->MemoryBlocksNums)
			{
				GhostLogW("There are still %ld blocks that have not been released, and there may be a memory leak!", status->MemoryBlocksNums);
			}
		}

		free(status);
		return GhostOK;
	}
	else {
		return GhostErrorMemMgrUninitialized;
	}
}
