/*******************************************************************************
 * @File   : $safeitemname$
 * @Path   : $rootnamespace$
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
// Self headers.
#include "GhostAppResourcePool.h"

// Standard headers.
#include <string.h>

// ThirdParty headers.

// Ghost headers.
#include "GhostLog.h"
#include "GhostMemoryManager.h"

/***********************************Defines************************************/



/***********************************Typedefs***********************************/
/// <summary>
/// Pair of app resource, binding pointer and destructor.
/// </summary>
typedef struct
{
	void* Resource;
	void(*Destroyer)(void*);
} GhostAppResPair_t;


/// <summary>
/// 
/// </summary>
typedef struct
{
	int AppResNum;
	int NextVacancyID;
	GhostMutex_t Mutex;
	GhostAppResPair_t* Pool;
} Pool_t;


/**********************************Prototypes**********************************/
/// <summary>
/// Compress and eliminate the vacancy in the resource pool.
/// This function will be called automaticly when the `NextVacancyID` 
///	equal to `AppResNum` - 1.
/// This function can be used to expand and narrow the resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="Pool">Resource pool pointer.</param>
/// <param name="Locked">Whether the resource pool is locked.</param>
/// <returns>Function execution result.</returns>
static GhostError_t ghostAppResPoolDensify(GhostAppResPool_t Pool, bool Locked);


/// <summary>
/// Resize ResPool capacity to specified size(if possible).
/// This function can be used to expand and narrow the resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="Pool">Resource pool pointer.</param>
/// <param name="TargetCapacity">Target capacity.</param>
/// <returns>Capacity of ResPool after resized.</returns>
static int ghostAppResPoolResize(GhostAppResPool_t ResPool, int TargetCapacity, bool Locked);


/// <summary>
/// Get the number of resources in the current resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <returns>Number of items.</returns>
static inline int ghostAppResPoolGetItemNum(GhostAppResPool_t ResPool, bool Locked);


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
GhostAppResPool_t GhostAppResPoolNew(int InitialCapactiy)
{
	// Allocate ResPool.
	Pool_t* pool = GhostMemMgrCalloc(1, sizeof(Pool_t));
	if (pool == NULL)
	{
		GhostLogE("Create Ghost AppResPool error, out of memory!");
		return NULL;
	}

	// Allocate buffer.
	pool->Pool = GhostMemMgrCalloc(InitialCapactiy, sizeof(GhostAppResPair_t));
	if (pool == NULL)
	{
		GhostLogE("Create Ghost AppResPool error, out of memory!");
		GhostMemMgrFree(pool);
		return NULL;
	}

	// Create mutex.
	if (IfGhostError(GhostMutexInit(&pool->Mutex)))
	{
		// Create mutex failed.
		GhostMemMgrFree(pool->Pool);
		GhostMemMgrFree(pool);
		return NULL;
	}
	else {
		// Create successfully.
		return (GhostAppResPool_t)pool;
	}
}


/// <summary>
/// Destroy all elements in ResPool and free memory.
/// Elements will be released in reverse order.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppResPoolFree(GhostAppResPool_t ResPool)
{
#if(MacroGhostDebug)
	// Check parameter.
	if (ResPool == NULL)
	{
		GhostLogE("GhostAppResPoolResize failed, Pool = NULL!");
		return GhostMutexErrUninitialized;
	}
#endif

	// Lock mutex.
	GhostMutexLock(&((Pool_t*)ResPool)->Mutex);

	Pool_t* resPool = (Pool_t*)ResPool;
	int capacity = GhostMemMgrGetPointorSize(resPool->Pool) / sizeof(GhostAppResPair_t);

	do {
		// Release all elements.
		for (int i = capacity - 1; i >= 0; i--)
		{
			GhostAppResPair_t* pair = (resPool->Pool + i);
			if (pair->Resource != NULL)
			{
				pair->Destroyer(pair->Resource);
#if(MacroGhostDebug)
				pair->Resource = NULL;
				pair->Destroyer = NULL;
#endif
			}
		}

		// Clear property.
		resPool->AppResNum = 0;
		resPool->NextVacancyID = 0;
		GhostMemMgrFree(resPool->Pool);
	} while (0);
	
	GhostMutexUnlock(&resPool->Mutex);
	// Destory mutex.
	GhostMutexDestroy(&resPool->Mutex);
	GhostMemMgrFree(resPool);

	return GhostOK;
}


/// <summary>
/// Compress and eliminate the vacancy in the resource pool.
/// This function will be called automaticly when the `NextVacancyID` 
///	equal to `AppResNum` - 1.
/// This function can be used to expand and narrow the resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <param name="Locked">Whether the resource pool is locked.</param>
/// <returns>Function execution result.</returns>
static GhostError_t ghostAppResPoolDensify(GhostAppResPool_t ResPool, bool Locked)
{
	GhostError_t ret = GhostOK;

	// Lock mutex.
	if (!Locked)
	{
#if(MacroGhostDebug)
		// Check parameter.
		if (ResPool == NULL)
		{
			GhostLogE("GhostAppResPoolResize failed, Pool = NULL!");
			return GhostMutexErrUninitialized;
		}
#endif
		// Lock ResPool.
		if (IfGhostError(ret = GhostMutexLock(&((Pool_t*)ResPool)->Mutex)))
		{
			return ret;
		}
	}

	Pool_t* resPool = (Pool_t*)ResPool;
	do {
		// Calculate basic parameters.
		int capacity = GhostMemMgrGetPointorSize(resPool->Pool) / sizeof(GhostAppResPair_t);
		if (capacity == resPool->AppResNum)
		{
			ret = GhostOK;
			break;
		}
		GhostAppResPair_t* pool = resPool->Pool;

		/// index:  0123456789..........
		///        ┌────────────────────┐
		///        │00011111110110101100│
		///        └───▲──────▲─────────┘
		/// front:─────┘      │
		/// back :────────────┘
		/// length = back - front.
		/// startaddress = pool + front
		/// destaddress = pool + totalLength
		int totalLength = 0;
		for (int front = 0; front < capacity; front++)
		{
			// Find front data.
			if ((pool + front)->Resource == NULL)
			{
				continue;
			}

			// Find back data.
			int back = front;
			for (; back < capacity; back++)
			{
				GhostAppResPair_t* pair = (pool + back);
				if ((pool + back)->Resource == NULL)
				{
					break;
				}
			}

			// Move data forward.
			int length = (back - front);
			memmove(pool + totalLength, pool + front, sizeof(GhostAppResPair_t) * length);

			// Calculate totalLength.
			totalLength += length;

			// Empty useless memory.
			/// index:  0123456789..........
			///        ┌────────────────────┐
			///        │00011111110110101100│
			///        └───▲──────▲─────────┘
			/// front:─────┘      │
			/// back :────────────┘
			/// 
			/// buffer after memmove:
			/// index:  0123456789..........
			///        ┌────────────────────┐
			///        │1111111***0110101100│
			///        └───────▲─▲──────────┘
			/// start:─────────┘ │
			/// end  :───────────┘
			/// start = max(totalLength, front)
			/// length = min(back - totalLength, back - front)
			/// size = length * sizeof(GhostAppResPair_t)
			
			// void* start = pool + max(totalLength, front);
			void* start = NULL;
			if (totalLength >= front)
			{
				start = pool + totalLength;
			}
			else {
				start = pool + front;
			}
			
			// length = min(back - totalLength, back - front);
			length = 0;
			int b_minus_t = back - totalLength;
			int b_minus_f = back - front;
			if (b_minus_t <= b_minus_f)
			{
				length = b_minus_t;
			}
			else {
				length = b_minus_f;
			}

			memset(start, 0x00, sizeof(GhostAppResPair_t) * length);

			front = back;
		}
		// Move NextVacancyID.
		resPool->NextVacancyID = resPool->AppResNum;
	} while (0);
	
	// Unlock mutex.
	if (!Locked)
	{
		// Unlock ResPool.
		return GhostMutexUnlock(&resPool->Mutex);
	}
	return ret;
}


/// <summary>
/// Resize ResPool capacity to specified size(if possible).
/// This function can be used to expand and narrow the resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <param name="Capacity">Target capacity.</param>
/// <returns>Capacity of ResPool after resized.</returns>
int GhostAppResPoolResize(GhostAppResPool_t ResPool, int Capacity)
{
	return ghostAppResPoolResize(ResPool, Capacity, false);
}


/// <summary>
/// Get the number of resources in the current resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <returns>Number of items.</returns>
int GhostAppResPoolGetItemNum(GhostAppResPool_t ResPool)
{
	return ghostAppResPoolGetItemNum(ResPool, false);
}


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
	void* Resource, void(*Destroyer)(void*))
{
#if(MacroGhostDebug)
	// Check parameter.
	if (ResPool == NULL)
	{
		GhostLogE("GhostAppResPoolAddItem failed, Pool = NULL!");
		return GhostAppResPoolErrParamIllegal;
	}
#endif

	// Check parameters.
	if (Resource == NULL)
	{
		GhostLogE("AppResPool add item failed, Resource is NULL!");
		return GhostAppResPoolErrParamIllegal;
	}
	
	if (Destroyer == NULL)
	{
		GhostLogE("AppResPool add item failed, Destroyer is NULL!"
			"It may cause memory leaks!");
		return GhostAppResPoolErrParamIllegal;
	}
	
	// Add item.
	GhostError_t ret = GhostOK;
	Pool_t* resPool = (Pool_t*)ResPool;

	// Lock mutex.
	GhostMutexLock(&resPool->Mutex);
	do {
		// Calculate basic parameters.
		int capacity = GhostMemMgrGetPointorSize(resPool->Pool) / sizeof(GhostAppResPair_t);
		
		// Check NextVacancyID.
		if (resPool->NextVacancyID >= capacity - 1)
		{
			// If full.
			if (resPool->AppResNum >= capacity - 1)
			{
				// Double capacity.
				if (capacity = ghostAppResPoolResize(ResPool, capacity * 2, true) 
					<= resPool->AppResNum - 1)
				{
					// Failed, out of memory.
					ret = GhostAppResPoolErrOutOfMemory;
					// break out.
					break;
				}
				
			}
			// Densification required.
			else {
				ghostAppResPoolDensify(ResPool, true);
			}
		}

		// Add item.
		(resPool->Pool + resPool->NextVacancyID)->Resource = Resource;
		(resPool->Pool + resPool->NextVacancyID)->Destroyer = Destroyer;
		resPool->AppResNum++;
		resPool->NextVacancyID++;
	} while (0);

	GhostMutexUnlock(&resPool->Mutex);
	return ret;
}


/// <summary>
/// Destory a resource.
/// This function keeps the order of the original items.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <param name="Resource">Resource pointor.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppResPoolFreeItem(GhostAppResPool_t ResPool, void* Resource)
{
#if(MacroGhostDebug)
	// Check parameter.
	if (ResPool == NULL)
	{
		GhostLogE("GhostAppResPoolFreeItem failed, Pool = NULL!");
		return GhostAppResPoolErrParamIllegal;
	}
#endif

	// Check parameters.
	if (Resource == NULL)
	{
		return GhostAppResPoolErrParamIllegal;
	}

	GhostError_t ret = GhostOK;
	Pool_t* resPool = (Pool_t*)ResPool;

	// Lock mutex.
	GhostMutexLock(&resPool->Mutex);
	do {
		// Calculate basic parameters.
		int capacity = GhostMemMgrGetPointorSize(resPool->Pool) / sizeof(GhostAppResPair_t);
		GhostAppResPair_t* pool = resPool->Pool;
		
		// looking for resource.
		int i = 0;
		for (; i < capacity; i++)
		{
			if ((pool + i)->Resource == Resource)
			{
				break;
			}
		}
		if (i == capacity)
		{
			if ((pool + i - 1) != Resource)
			{
				ret = GhostAppResPoolErrResNotFound;
				break;
			}
			else {
				i--;
			}
		}

		// Free Item.
		(pool + i)->Destroyer((pool + i)->Resource);
		(pool + i)->Resource = NULL;
		(pool + i)->Destroyer = NULL;
		resPool->AppResNum--;
		if (i == resPool->NextVacancyID - 1)
		{
			resPool->NextVacancyID--;
		}

		// Densify ResPool.
		ret = ghostAppResPoolDensify(ResPool, true);
	} while (0);

	GhostMutexUnlock(&resPool->Mutex);
	return ret;
}

/// <summary>
/// Resize ResPool capacity to specified size(if possible).
/// This function can be used to expand and narrow the resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="Pool">Resource pool pointer.</param>
/// <param name="TargetCapacity">Target capacity.</param>
/// <returns>Capacity of ResPool after resized.</returns>
static int ghostAppResPoolResize(GhostAppResPool_t ResPool, int TargetCapacity, bool Locked)
{
#if(MacroGhostDebug)
	// Check parameter.
	if (ResPool == NULL)
	{
		GhostLogE("GhostAppResPoolResize failed, Pool = NULL!");
		return 0;
	}
#endif

	int ret = 0;
	Pool_t* resPool = (Pool_t*)ResPool;
	// Lock mutex.
	if (!Locked)
	{
		GhostMutexLock(&resPool->Mutex);
	}

	do {
		// If without densify...
		int capacity = GhostMemMgrGetPointorSize(resPool->Pool) / sizeof(GhostAppResPair_t);
		if (TargetCapacity == capacity)
		{
			ret = capacity;
			break;
		}

		// Densify ResPool.
		if (IfGhostError(ghostAppResPoolDensify(resPool, true)))
		{
			GhostLogE("ghostAppResPoolDensify failed.");
			ret = 0;
			break;
		}
		else {
			if (TargetCapacity >= resPool->AppResNum)
			{
				GhostAppResPair_t* newPool = GhostMenMgrRealloc(resPool->Pool,
					TargetCapacity * sizeof(GhostAppResPair_t));
				if (newPool == NULL)
				{
					GhostLogE("GhostAppResPoolResize failed, out of memory.");
					ret = resPool->AppResNum;
					break;
				}
				else {
					resPool->Pool = newPool;
					memset((resPool->Pool + resPool->NextVacancyID), 0x00, 
						sizeof(GhostAppResPair_t) * (TargetCapacity - resPool->NextVacancyID));
					ret = TargetCapacity;
					break;
				}
			}
			if (TargetCapacity < resPool->AppResNum)
			{
				GhostAppResPair_t* newPool = GhostMenMgrRealloc(resPool->Pool,
					resPool->AppResNum * sizeof(GhostAppResPair_t));
				ret = resPool->AppResNum;
				break;
			}
		}
	} while (0);

	// Unlock mutex.
	if (!Locked)
	{
		GhostMutexUnlock(&resPool->Mutex);
	}
	return ret;
}


/// <summary>
/// Get the number of resources in the current resource pool.
/// Thread safety:
///		Yes.
/// </summary>
/// <param name="ResPool">Resource pool pointer.</param>
/// <returns>Number of items.</returns>
static inline int ghostAppResPoolGetItemNum(GhostAppResPool_t ResPool, bool Locked)
{
#if(MacroGhostDebug)
	// Check parameter.
	if (ResPool == NULL)
	{
		GhostLogE("GhostAppResPoolGetItemNum failed, ResPool = NULL!");
		return 0;
	}
#endif

	int ret = 0;
	Pool_t* resPool = (Pool_t*)ResPool;
	// Lock mutex.
	if (!Locked)
	{
		GhostMutexLock(&resPool->Mutex);
	}

	ret = GhostMemMgrGetPointorSize(resPool->Pool) / sizeof(GhostAppResPair_t);

	// Unlock mutex.
	if (!Locked)
	{
		GhostMutexUnlock(&resPool->Mutex);
	}
	return ret;
}


#if(MacroGhostDebug)
#include <math.h>
/// <summary>
/// Unit test.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostAppResPoolUnitTest(void)
{
	while (1)
	{
		// Create ResPool.
		GhostAppResPool_t pool = GhostAppResPoolNew(8);
		void* ptr[100] = { NULL };

		// Add item to ResPool.
		for (int i = 0; i < 100; i++)
		{
			ptr[i] = GhostMemMgrMalloc(10);
			GhostAppResPoolAddItem(pool, ptr[i], GhostMemMgrFree);
		}

		// Delete item randomly.
		for (int i = 0; i < 50; i++)
		{
			int ii = rand() % 100;
			if (ptr[ii] != NULL)
			{
				GhostAppResPoolFreeItem(pool, ptr[ii]);
				ptr[ii] = NULL;
			}
		}

		// Resize.
		GhostAppResPoolResize(pool, GhostAppResPoolGetItemNum(pool));

		// Add new item.
		for (int i = 0; i < 100; i++)
		{
			GhostAppResPoolAddItem(pool, GhostMemMgrMalloc(10), GhostMemMgrFree);
		}

		// Free ResPool.
		GhostAppResPoolFree(pool);
	}

	return GhostOK;
}
#endif
