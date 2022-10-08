################################################################################
 # @Path   : $rootnamespace$
 # @Module : 
 # 
 # @Author : $username$
 # @Time   : $time$
 # @license: AGPL-3.0(https://github.com/h13-0/Ghost/blob/master/LICENSE)
 # @Notes  :
 #		The following are set after configuration is done:
 #			GHOST_APP_FRM_INCLUDE_DIRS
 #			GHOST_APP_FRM_SOURCES_FILES
 #
################################################################################
project(GhostAppFramework)

# Set header paths.
set(
	GHOST_APP_FRM_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/AppAPIs"
	CACHE PATH "Ghost app framework header file paths list."
)

include_directories(
	"${GHOST_APP_FRM_INCLUDE_DIRS}"
)


# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	# Source files here:
	"${PROJECT_SOURCE_DIR}/GhostAppFramework.c"
	"${PROJECT_SOURCE_DIR}/GhostAppResourcePool.c"

	"${PROJECT_SOURCE_DIR}/AppAPIs/GhostAppAPIs.c"
)

# Include header paths.
target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_NAME}_INCLUDE_DIRS"
)
