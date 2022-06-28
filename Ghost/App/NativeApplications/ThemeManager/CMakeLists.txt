# The following are set after configuration is done:
# GHOST_APP_THEME_MGR_INCLUDE_DIRS

project(GhostAppThemeMgr)

# Include submodules.
## Built in themes.
add_subdirectory("${PROJECT_SOURCE_DIR}/Themes")
include_directories("${GHOST_COMPONENT_THEMES_INCLUDE_DIRS}")

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/GhostThemeManager.c"
)

# Set header paths.
set(
	GHOST_APP_THEME_MGR_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost theme manager header file paths list."
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)

# Link libraries.
target_link_libraries(
	${PROJECT_NAME}
	GhostCompThemes
)
