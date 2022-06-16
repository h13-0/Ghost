# The following are set after configuration is done:
# GHOST_WINDOWS_FSP_INCLUDE_DIRS

project(GhostWindowsFileSystemPatch VERSION 0.0.1)

# Generate libraries.
add_library(
	${PROJECT_NAME} 
	STATIC 
	"${PROJECT_SOURCE_DIR}/GhostFileSystemPatch.c"
)
# Set header paths.
set(
	GHOST_WINDOWS_FSP_INCLUDE_DIRS
	"${CMAKE_CURRENT_LIST_DIR}"
	CACHE PATH "Ghost File System Patch interface header file paths list."
)

include_directories(
	"${GHOST_WINDOWS_FSP_INCLUDE_DIRS}"
)
