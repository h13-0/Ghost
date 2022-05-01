# The following are set after configuration is done:
# GHOST_APP_INCLUDE_DIRS
# GHOST_APP_LIBRARIES

project(GhostApps)

# Include commen directories.
include_directories("${PROJECT_SOURCE_DIR}")

# Include submodules.
## Components.
### Application Manager.
add_subdirectory("${PROJECT_SOURCE_DIR}/Components/ApplicationManager")
include_directories("${GHOST_COMPONENT_APP_MGR_INCLUDE_DIRS}")

## Applications.
add_subdirectory("${PROJECT_SOURCE_DIR}/NativeApplications/Launcher")
include_directories("${GHOST_APP_LAUNCHER_INCLUDE_DIRS}")

# Set header paths.
set(
	GHOST_APP_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost Apps header file path list."
)

include_directories(
	"${GHOST_APP_INCLUDE_DIRS}"
)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${CMAKE_CURRENT_LIST_DIR}/App.c"
)

# Link libraries.
target_link_libraries(
	${PROJECT_NAME}
	
	GhostComponentAppMgr

	GhostAppLauncher
)

