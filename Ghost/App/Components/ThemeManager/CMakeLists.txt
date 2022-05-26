# The following are set after configuration is done:
# GHOST_COMPONENT_THEME_MGR_INCLUDE_DIRS

project(GhostComponentThemeMgr)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/GhostThemeManager.c"
)

# Set header paths.
set(
	GHOST_COMPONENT_THEME_MGR_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost theme manager header file paths list."
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)



