# The following variables are set after configuration is done:
# GHOST_QT_INCLUDE_DIRS
# GHOST_QT_SOURCE_FILES
# GHOST_QT_LINK_LIBRARIES

# Check dependencies.
set(CMAKE_AUTOMOC ON) # Meta-Object Compiler
set(CMAKE_AUTOUIC ON) # User Interface Compiler
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

# Set header paths.
set(
	GHOST_QT_INCLUDE_DIRS
	${Qt5Widgets_INCLUDE_DIRS}
	${CMAKE_CURRENT_BINARY_DIR}
	"${PROJECT_SOURCE_DIR}/Platforms/WindowsSimulator/QT"
)

# Set source files.
QT5_WRAP_UI(GHOST_QT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/Platforms/WindowsSimulator/QT/Simulator.ui")
aux_source_directory(${PROJECT_SOURCE_DIR}/Platforms/WindowsSimulator/QT GHOST_QT_SOURCE_FILES)

# Set link libraries.
set(
	GHOST_QT_LINK_LIBRARIES
	"Qt5::Widgets"
	"Qt5::Core"
	"Qt5::Gui"
)
