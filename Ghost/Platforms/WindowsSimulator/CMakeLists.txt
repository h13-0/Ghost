# Include Platform configs and Tools headers.
include_directories(
	"${CMAKE_CURRENT_LIST_DIR}"
	"${PROJECT_SOURCE_DIR}/App"
	"${PROJECT_SOURCE_DIR}/Drivers"
	"${PROJECT_SOURCE_DIR}/Tools/Macro"

)

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

#### lua
include("${CMAKE_CURRENT_LIST_DIR}/lua/CMakeLists.txt")
add_subdirectory("${PROJECT_SOURCE_DIR}/ThirdParty/lua")
include_directories("${LUA_INCLUDE_DIRS}")

### Platforms layer.
#### QT.
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/QT")
include_directories(${GHOST_WINDOWS_QSIM_INCLUDE_DIRS})

### Driver layer.
#### Thread (use pthread).
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/Thread/pthread")
include_directories("${GHOST_THREAD_INCLUDE_DIRS}")

#### Clock.
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/Clock/StandardClock")
include_directories(${GHOST_STANDARD_CLOCK_INCLUDE_DIRS})
#### FileSystem
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/FileSystem")
include_directories(${GHOST_FILESYSTEM_INCLUDE_DIRS})
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
	# ThirdParty.
	lvgl
	lua
	# Platform.
	GhostWindowsQT_Simulator

	# Drivers.
	GhostThread
	
	QT_SimulatorScreen 
	GhostStandardClock
	GhostFileSystem
	GhostApps

)
