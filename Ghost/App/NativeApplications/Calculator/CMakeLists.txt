################################################################################
 # @Path   : $rootnamespace$
 # @Module : 
 # 
 # @Author : $username$
 # @Time   : $time$
 # @license: AGPL-3.0(https://github.com/h13-0/Ghost/blob/master/LICENSE)
 # @Notes  :
 #		The following are set after configuration is done:
 #			GHOST_CALCULATOR_INCLUDE_DIRS
 #			GHOST_CALCULATOR_SOURCES_FILES
 #
################################################################################
project(GHOST_CALCULATOR)

# Set header paths.
set(
	GHOST_CALCULATOR_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost application framework header file paths list."
)

include_directories(
	"${GHOST_CALCULATOR_INCLUDE_DIRS}"
)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	# Source files here:
	"${PROJECT_SOURCE_DIR}/GhostCalculator.c"
)

# Include header paths.
target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${GHOST_CALCULATOR_INCLUDE_DIRS}"
)

