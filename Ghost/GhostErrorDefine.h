#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif
	typedef enum
	{
		GhostNoError = 0,
		GhostSoftwareLayerError = 1,
		GhostDriverLayerError = 2,
		GhostPlatformLayerError = 3,
	} LayerErrorCode_t;

	typedef struct
	{
		LayerErrorCode_t LayerErrorCode : 8;
		int ModuleErrorCode : 8;
		int SubErrorCode : 16;
	} GhostError_t;

	static inline bool IfGhostError(GhostError_t Error)
	{
		return (Error.LayerErrorCode != GhostNoError);
	}


	/// <summary>
	/// Check whether the Ghost function is successfully executed. If not, **return** the return value of the Ghost function in advance.
	///		This function **CANNOT** be understood as a common C language function.
	///		Please use this function with **CAUTION:**
	///			When GhostErrorRet is not GhostOK, the operation of this function will be **TERMINATED** in advance and GhostErrorRet will be returned.
	/// </summary>
	/// <param name="LogLevel">Log level.</param>
	/// <param name="GhostErrorRet">Function with GhostError_t as return value or return value of GhostError_t.</param>
#define GhostTerminateIfErr(GhostErrorRet)            do{ \
                                                            if(IfGhostError(GhostErrorRet)) { \
                                                                return GhostErrorRet; \
                                                            } \
                                                        } while(0);
	

	/// <summary>
	/// Declare GhostError_t.
	/// </summary>
	/// <param name="LayerErrorCode"></param>
	/// <param name="ModuleErrorCode"></param>
	/// <param name="SubErrorCode"></param>
	/// <returns>GhostError in GhostError_t.</returns>
#ifdef __cplusplus
#define DeclareGhostError(LayerErrorCode, ModuleErrorCode, SubErrorCode) \
	{ LayerErrorCode, ModuleErrorCode, SubErrorCode }
#else
#define DeclareGhostError(LayerErrorCode, ModuleErrorCode, SubErrorCode) \
	(GhostError_t){ LayerErrorCode, ModuleErrorCode, SubErrorCode }
#endif

	/// <summary>
	/// Define GhostOK.
	/// </summary>
#define GhostOK     DeclareGhostError(GhostNoError, 0, 0)


#ifdef __cplusplus
}
#endif
