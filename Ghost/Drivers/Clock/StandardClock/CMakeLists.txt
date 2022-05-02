# The following are set after configuration is done:
# GHOST_STANDARD_CLOCK_INCLUDE_DIRS

project(GhostStandardClock VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)

# Link libraries.
add_library(
	${PROJECT_NAME} 
	STATIC 
	"${PROJECT_SOURCE_DIR}/GhostStandardClock.cpp"
)

# Set header paths.
set(
	GHOST_STANDARD_CLOCK_INCLUDE_DIRS
	"${CMAKE_CURRENT_LIST_DIR}/.."
	CACHE PATH "Ghost Standard Clock interface header file paths list."
)

include_directories(
	"${GHOST_STANDARD_CLOCK_INCLUDE_DIRS}"
)
