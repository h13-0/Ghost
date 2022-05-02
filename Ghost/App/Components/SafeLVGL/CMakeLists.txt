# The following are set after configuration is done:
# GHOST_SAFELVGL_INCLUDE_DIRS

project(SafeLVGL VERSION 0.0.1)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/GhostSafeLVGL.c"
)

# Set header paths.
set(
	GHOST_SAFELVGL_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost SafeLVGL header file path list."
)

include_directories(
	"${GHOST_SAFELVGL_INCLUDE_DIRS}"
)

