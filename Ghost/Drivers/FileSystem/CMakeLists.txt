# The following are set after configuration is done:
# GHOST_FILESYSTEM_INCLUDE_DIRS

project(GhostFileSystem)

# Link libraries.
add_library(
	${PROJECT_NAME} 
	STATIC 
	"${PROJECT_SOURCE_DIR}/GhostFileSystem.c"
)

# Set header paths.
set(
	GHOST_FILESYSTEM_INCLUDE_DIRS
	"${CMAKE_CURRENT_LIST_DIR}"
	CACHE PATH "Ghost File System interface header file paths list."
)

include_directories(
	"${GHOST_FILESYSTEM_INCLUDE_DIRS}"
)

