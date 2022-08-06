# The following are set after configuration is done:
# GHOST_APP_THEME_MGR_INCLUDE_DIRS

project(GhostAppThemeMgr)

# Include submodules.
## Built in themes.
aux_source_directory("${PROJECT_SOURCE_DIR}/Themes" THEME_MGR_SOURCES)

# Set header paths.
set(
	GHOST_APP_THEME_MGR_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/Themes"
	CACHE PATH "Ghost theme manager header file paths list."
)

include_directories(
	"${GHOST_APP_THEME_MGR_INCLUDE_DIRS}"
)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/GhostThemeManager.c"
	"${THEME_MGR_SOURCES}"
)
