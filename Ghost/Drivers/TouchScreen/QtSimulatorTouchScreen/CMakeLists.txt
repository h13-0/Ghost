project(QtSimulatorTouchScreen)

add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/QtSimulatorTouchScreen.c"
)

include_directories(
	"${PROJECT_SOURCE_DIR}/.."
)

# Set header paths.
set(
	GHOST_TOUCH_SCREEN_SCREEN_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}/.."
	CACHE PATH "Ghost screen interface header file paths list."
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)
