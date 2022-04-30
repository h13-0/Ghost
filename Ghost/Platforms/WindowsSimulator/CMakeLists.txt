# Include Platform configs headers.
include_directories("${CMAKE_CURRENT_LIST_DIR}")

# find dependent packages.
find_package(pthreads CONFIG REQUIRED)
include_directories(${PThreads4W_INCLUDE_DIR})

# Build executable file.
## Include submodules.
### ThirdParty layer.
#### lvgl.
include("${CMAKE_CURRENT_LIST_DIR}/lvgl/CMakeLists.txt")
add_subdirectory("${PROJECT_SOURCE_DIR}/ThirdParty/lvgl")
include_directories("${PROJECT_SOURCE_DIR}/ThirdParty/lvgl")

### Platforms layer.
#### QT.
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/QT")
include_directories(${GHOST_WINDOWS_QSIM_INCLUDE_DIRS})

### Driver layer.
#### Screen.
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/Screen/QT_SimulatorScreen")
#### Touch Screen.
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/TouchScreen")

### Application layer.
add_subdirectory("${PROJECT_SOURCE_DIR}/App")
include_directories("${GHOST_APP_INCLUDE_DIRS}")

## Set header paths.
include_directories(${GhostWindowsQT_INCLUDE_DIRS})

## Add source files.
set(
	SOURCE_FILES
	${GHOST_APP_SOURCE_FILES}
	${CMAKE_CURRENT_LIST_DIR}/main.c
)

# Compile executable file.
add_executable(WindowsSimulator ${SOURCE_FILES})
target_link_libraries(
	WindowsSimulator 
	GhostApps 
	QT_SimulatorScreen 
	GhostWindowsQT_Simulator 
	${PThreads4W_LIBRARY} 
	lvgl
)
