# The following are set after configuration is done:
# GHOST_WINDOWS_QSIM_INCLUDE_DIRS

project(GhostWindowsQtSimulator)

# Check dependencies.
set(CMAKE_AUTOMOC ON) # Meta-Object Compiler
set(CMAKE_AUTOUIC ON) # User Interface Compiler

# Check Qt6.
find_package(Qt6 COMPONENTS Widgets Core Gui)
if(NOT Qt6_FOUND)
	# Qt6 not found, use Qt5.
	message(WARNING "Qt6 not found, Qt5 will be used.")
	find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
endif()

# Set source files.
if(Qt6_FOUND)
	QT6_WRAP_UI(GHOST_QT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/Simulator.ui")
else()
	QT5_WRAP_UI(GHOST_QT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/Simulator.ui")
endif()
aux_source_directory(${PROJECT_SOURCE_DIR} GHOST_QT_SOURCE_FILES)

# Set executable icon.
if(WIN32)
	set(GHOST_QT_SOURCE_FILES "${GHOST_QT_SOURCE_FILES}" "${PROJECT_SOURCE_DIR}/Icon.qrc")
elseif(UNIX)
	# TODO: Icon in linux.
else()
	# I don't have iMac.
endif()

# Generate libraries.
add_library(
	${PROJECT_NAME} 
	STATIC 
	${GHOST_QT_SOURCE_FILES}
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

# Add Qt resource file.
set(QRC_SOURCE_FILES Resources.qrc)

# Set header paths.
set(
	GHOST_WINDOWS_QSIM_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	"${CMAKE_CURRENT_BINARY_DIR}"
	CACHE PATH "Ghost Windows QT interface header file paths list."
)

if(Qt6_FOUND)
	include_directories(
		"${GHOST_WINDOWS_QSIM_INCLUDE_DIRS}"
		"${Qt6Widgets_INCLUDE_DIRS}"
	)
else()
	include_directories(
		"${GHOST_WINDOWS_QSIM_INCLUDE_DIRS}"
		"${Qt5Widgets_INCLUDE_DIRS}"
	)
endif()
