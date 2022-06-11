# The following are set after configuration is done:
# GHOST_APP_MGR_INCLUDE_DIRS

project(GhostComponentAppMgr)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/GhostApplicationManager.c"
)

# Set header paths.
set(
	GHOST_APP_MGR_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost application manager header file paths list."
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)
