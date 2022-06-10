# The following are set after configuration is done:
# GHOST_APP_INCLUDE_DIRS
# GHOST_APP_LIBRARIES

project(GhostApps)

# Include commen directories.
include_directories("${PROJECT_SOURCE_DIR}")

# Include submodules.
## Components.
### Ghost Log.
add_subdirectory("${PROJECT_SOURCE_DIR}/Components/Log")
include_directories("${GHOST_APP_LOG_INCLUDE_DIRS}")

### Application Manager.
add_subdirectory("${PROJECT_SOURCE_DIR}/Components/ApplicationManager")
include_directories("${GHOST_COMPONENT_APP_MGR_INCLUDE_DIRS}")

### SafeLVGL
add_subdirectory("${PROJECT_SOURCE_DIR}/Components/SafeLVGL")
include_directories("${GHOST_SAFELVGL_INCLUDE_DIRS}")

### Theme manager.
add_subdirectory("${PROJECT_SOURCE_DIR}/Components/ThemeManager")
include_directories("${GHOST_COMPONENT_THEME_MGR_INCLUDE_DIRS}")

## Applications.
### Permission manager.
add_subdirectory("${PROJECT_SOURCE_DIR}/NativeApplications/PermissionManager")
include_directories("${GHOST_APP_PM_INCLUDE_DIRS}")

### Launcher.
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

	GhostAppPermissionManager
	GhostComponentAppMgr
	SafeLVGL

	GhostAppLauncher
)

