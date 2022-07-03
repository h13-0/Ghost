# The following are set after configuration is done:
# GHOST_APP_INCLUDE_DIRS
# GHOST_APP_LIBRARIES

project(GhostApps)

# Include commen directories.
include_directories("${PROJECT_SOURCE_DIR}")

# Include submodules.
## Components.
### SafeLVGL
add_subdirectory("${PROJECT_SOURCE_DIR}/Components/SafeLVGL")
include_directories("${GHOST_CMP_SAFELVGL_INCLUDE_DIRS}")

## Applications.
### Application Manager.
add_subdirectory("${PROJECT_SOURCE_DIR}/NativeApplications/ApplicationManager")
include_directories("${GHOST_APP_APP_MGR_INCLUDE_DIRS}")

### Theme manager.
add_subdirectory("${PROJECT_SOURCE_DIR}/NativeApplications/ThemeManager")
include_directories("${GHOST_APP_THEME_MGR_INCLUDE_DIRS}")

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

	# Components.
	GhostCmpSafeLVGL

	# NativeApplications.
	GhostAppAppMgr
	GhostAppThemeMgr
	GhostAppLauncher
)

