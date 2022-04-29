# The following are set after configuration is done:
# GHOST_APP_INCLUDE_DIRS
# GHOST_APP_LIBRARIES

project(GhostApps)

# Set header paths.
set(
	GHOST_APP_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}/App"
	"${PROJECT_SOURCE_DIR}/App/Log"
	CACHE PATH "Ghost Apps header file path list."
)

include_directories(
	"${GHOST_APP_INCLUDE_DIRS}"
)

add_library(
	${PROJECT_NAME}
	STATIC
	"${CMAKE_CURRENT_LIST_DIR}/App.c"
)


# Set link libraries.


