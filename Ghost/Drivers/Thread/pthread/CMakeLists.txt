# The following are set after configuration is done:
# GHOST_THREAD_INCLUDE_DIRS

project(GhostThread VERSION 0.0.1)

# Link libraries.
add_library(
	${PROJECT_NAME} 
	STATIC 
	"${PROJECT_SOURCE_DIR}/GhostThread.c"
)

target_link_libraries(
	${PROJECT_NAME}
	${PThreads4W_LIBRARY}
)
 

# Set header paths.
set(
	GHOST_THREAD_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost thread interface header file paths list."
)

include_directories(
	"${GHOST_THREAD_INCLUDE_DIRS}"
)
