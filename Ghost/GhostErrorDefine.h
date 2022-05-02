#pragma once

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

#ifdef __cplusplus
#define DeclareGhostError(LayerErrorCode, ModuleErrorCode, SubErrorCode) \
	{ LayerErrorCode, ModuleErrorCode, SubErrorCode }
#else
#define DeclareGhostError(LayerErrorCode, ModuleErrorCode, SubErrorCode) \
	(GhostError_t){ LayerErrorCode, ModuleErrorCode, SubErrorCode }
#endif

#define GhostOK     DeclareGhostError(GhostNoError, 0, 0)

#ifdef __cplusplus
}
#endif
