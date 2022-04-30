project(QT_SimulatorScreen)

add_library(
	${PROJECT_NAME}
	STATIC
	"${CMAKE_CURRENT_LIST_DIR}/QT_SimulatorScreen.c"
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}"
)
