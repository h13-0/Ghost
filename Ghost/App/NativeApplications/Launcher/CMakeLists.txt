# The following are set after configuration is done:
# GHOST_APP_LAUNCHER_INCLUDE_DIRS

project(GhostAppLauncher)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/GhostLauncher.c"
)

# Set header paths.
set(
	GHOST_APP_LAUNCHER_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost launcher header file paths list."
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)
