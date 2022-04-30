# The following are set after configuration is done:
# GHOST_WINDOWS_QSIM_INCLUDE_DIRS

project(GhostWindowsQT_Simulator)

# Check dependencies.
set(CMAKE_AUTOMOC ON) # Meta-Object Compiler
set(CMAKE_AUTOUIC ON) # User Interface Compiler
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

# Set source files.
QT5_WRAP_UI(GHOST_QT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/Simulator.ui")
aux_source_directory(${PROJECT_SOURCE_DIR} GHOST_QT_SOURCE_FILES)

# Link libraries.
add_library(
	${PROJECT_NAME} 
	STATIC 
	${GHOST_QT_SOURCE_FILES}
)
target_link_libraries(
	${PROJECT_NAME}
	"Qt5::Widgets"
	"Qt5::Core"
	"Qt5::Gui"
)

# Set header paths.
set(
	GHOST_WINDOWS_QSIM_INCLUDE_DIRS
	"${CMAKE_CURRENT_LIST_DIR}"
	"${CMAKE_CURRENT_BINARY_DIR}"
	CACHE PATH "Ghost Windows QT interface header file paths list."
)

include_directories(
	"${GHOST_WINDOWS_QT_INCLUDE_DIRS}"
	"${Qt5Widgets_INCLUDE_DIRS}"
)
