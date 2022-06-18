# The following are set after configuration is done:
# GHOST_QSIM_INCLUDE_DIRS
# GHOST_QSIM_SOURCE_FILES

cmake_minimum_required(VERSION 3.0)

project(GhostQtSimulator)

# Check dependencies.
set(CMAKE_AUTOMOC ON) # Meta-Object Compiler
set(CMAKE_AUTOUIC ON) # User Interface Compiler
set(CMAKE_AUTORCC ON) # Automatically process QRC files

# Check Qt6.
find_package(Qt6 COMPONENTS Widgets Core Gui)
if(NOT Qt6_FOUND)
	# Qt6 not found, use Qt5.
	message(WARNING "Qt6 not found, Qt5 will be used.")
	find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
endif()

# Add Qt resource file.
set(QRC_SOURCE_FILES "${PROJECT_SOURCE_DIR}/Resources.qrc")

# Set source files.
if(Qt6_FOUND)
	Qt6_wrap_ui(GHOST_QT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/Simulator.ui")
	Qt6_add_resources(${QRC_SOURCE_FILES})
else()
	Qt5_wrap_ui(GHOST_QT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/Simulator.ui")
	Qt5_add_resources(${QRC_SOURCE_FILES})
endif()
aux_source_directory(${PROJECT_SOURCE_DIR} GHOST_QT_SOURCE_FILES)

# Set executable icon.
if(WIN32)
	set(GHOST_QT_SOURCE_FILES "${GHOST_QT_SOURCE_FILES}")
elseif(UNIX)
	# TODO: Icon in linux.
else()
	# I don't have iMac.
endif()

# Generate libraries.
add_library(
	${PROJECT_NAME} 
	STATIC 
	"${GHOST_QT_SOURCE_FILES}"
	"${QRC_SOURCE_FILES}"
)

# Link libraries.
if(Qt6_FOUND)
	target_link_libraries(
		${PROJECT_NAME}
		"Qt6::Widgets"
		"Qt6::Core"
		"Qt6::Gui"
	)
else()
	target_link_libraries(
		${PROJECT_NAME}
		"Qt5::Widgets"
		"Qt5::Core"
		"Qt5::Gui"
	)
endif()

# Set header paths.
set(
	GHOST_QSIM_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	"${CMAKE_CURRENT_BINARY_DIR}"
	CACHE PATH "Ghost Qt interface header file paths list."
)

# Set source files.
set(
	GHOST_QSIM_SOURCE_FILES
	"${PROJECT_SOURCE_DIR}/Icon.rc"
	CACHE PATH "Ghost Qt source files list."
)

if(Qt6_FOUND)
	include_directories(
		"${GHOST_QSIM_INCLUDE_DIRS}"
		"${Qt6Widgets_INCLUDE_DIRS}"
	)
else()
	include_directories(
		"${GHOST_QSIM_INCLUDE_DIRS}"
		"${Qt5Widgets_INCLUDE_DIRS}"
	)
endif()
