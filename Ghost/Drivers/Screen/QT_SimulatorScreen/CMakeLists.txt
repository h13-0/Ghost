project(QT_SimulatorScreen)

add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/QT_SimulatorScreen.c"
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)
