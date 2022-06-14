# The following are set after configuration is done:
# GHOST_COMPONENT_THEMES_INCLUDE_DIRS

project(GhostCompThemes)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	# Big White
	"${PROJECT_SOURCE_DIR}/GhostBigWhite.c"

)

# Set header paths.
set(
	GHOST_COMPONENT_THEMES_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost built in themes header file paths list."
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)
