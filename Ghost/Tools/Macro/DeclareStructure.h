#pragma once

#ifndef MacroDeclareStructure
#ifdef __cplusplus
#define MacroDeclareStructure(TypedefStructure, ...) \
	({ ##__VA_ARGS__ })
#else
#define MacroDeclareStructure(TypedefStructure, ...) \
	(TypedefStructure){ ##__VA_ARGS__ }
#endif
#endif
