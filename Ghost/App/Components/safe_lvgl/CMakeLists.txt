################################################################################
 # @Path   : $rootnamespace$
 # @Module : 
 # 
 # @Author : $username$
 # @Time   : $time$
 # @license: AGPL-3.0(https://github.com/h13-0/Ghost/blob/master/LICENSE)
 # @Notes  :
 #		The following are set after configuration is done:
 #			GHOST_$PROJECTNAME$_INCLUDE_DIRS
 #			GHOST_$PROJECTNAME$_SOURCES_FILES
 #
################################################################################
project(safe_lvgl)

# Set header paths.
set(
	GHOST_SAFE_LVGL_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost safe_lvgl header paths list."
)

include_directories(
	"GHOST_SAFE_LVGL_INCLUDE_DIRS"
)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	# Source files here:
	"${PROJECT_SOURCE_DIR}/safe_lvgl.c"
)

# Include header paths.
target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "GHOST_SAFE_LVGL_INCLUDE_DIRS"
)

