project(QT_GraphicsView)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

add_definitions(-DUseQT_GraphicsView)


add_library(
	${PROJECT_NAME}
	STATIC
	"${CMAKE_CURRENT_LIST_DIR}/QT_GraphicsView.c"
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${CMAKE_CURRENT_LIST_DIR}"
)
