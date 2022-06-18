# The following are set after configuration is done:
# GHOST_CMP_SAFELVGL_INCLUDE_DIRS

project(GhostCmpSafeLVGL VERSION 0.0.1)

# Find 
file(GLOB_RECURSE SAFE_LVGL_SOURCE_FILES "${PROJECT_SOURCE_DIR}/*.c")

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${SAFE_LVGL_SOURCE_FILES}"
)

# Set header paths.
set(
	GHOST_CMP_SAFELVGL_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost SafeLVGL header file path list."
)

include_directories(
	"${GHOST_CMP_SAFELVGL_INCLUDE_DIRS}"
)

