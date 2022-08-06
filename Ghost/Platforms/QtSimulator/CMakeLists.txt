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

#### cJSON
#add_subdirectory("${PROJECT_SOURCE_DIR}/ThirdParty/cJSON")
set(
	SOURCE_FILES
	${SOURCE_FILES}
	"${PROJECT_SOURCE_DIR}/ThirdParty/cJSON/cJSON.c"
)
include_directories("${PROJECT_SOURCE_DIR}/ThirdParty/cJSON")

#### lua
include("${CMAKE_CURRENT_LIST_DIR}/lua/CMakeLists.txt")
add_subdirectory("${PROJECT_SOURCE_DIR}/ThirdParty/lua")
include_directories("${LUA_INCLUDE_DIRS}")

#### list
add_definitions(
	"-DLIST_CONFIG_H=GhostMemoryManager.h"
	"-DLIST_MALLOC=GhostMemMgrMalloc"
	"-DLIST_FREE=GhostMemMgrFree"
)
set(
	SOURCE_FILES
	${SOURCE_FILES}
	"${PROJECT_SOURCE_DIR}/ThirdParty/list/src/list.c"
	"${PROJECT_SOURCE_DIR}/ThirdParty/list/src/list_iterator.c"
	"${PROJECT_SOURCE_DIR}/ThirdParty/list/src/list_node.c"
)
include_directories("${PROJECT_SOURCE_DIR}/ThirdParty/list/src/")

### Platforms layer.
#### Qt.
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Qt")
include_directories("${GHOST_QSIM_INCLUDE_DIRS}")
set(SOURCE_FILES "${SOURCE_FILES}" "${GHOST_QSIM_SOURCE_FILES}")

#### FileSystemPatch
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/FileSystemPatch")
include_directories(${GHOST_FSP_INCLUDE_DIRS})

### Driver layer.
#### Thread (use pthread).
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/Thread/pthread")
include_directories("${GHOST_THREAD_INCLUDE_DIRS}")

#### Memory manager.
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/MemoryManager")
include_directories("${GHOST_MMGR_INCLUDE_DIRS}")

#### Clock.
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/Clock/StandardClock")
include_directories(${GHOST_STANDARD_CLOCK_INCLUDE_DIRS})

#### Log.
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/Log")
include_directories("${GHOST_LOG_INCLUDE_DIRS}")

#### FileSystem
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/FileSystem")
include_directories(${GHOST_FILESYSTEM_INCLUDE_DIRS})
#### Screen.
add_subdirectory("${PROJECT_SOURCE_DIR}/Drivers/Screen/QtSimulatorScreen")
include_directories("${GHOST_SCREEN_INCLUDE_DIRS}")
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
	${SOURCE_FILES}
	${GHOST_APP_SOURCE_FILES}
	${CMAKE_CURRENT_LIST_DIR}/main.c
)


# Compile executable file.
add_executable(QtSimulator ${SOURCE_FILES})


set_target_properties(
	QtSimulator
	PROPERTIES
	STATIC_LIBRARY_FLAGS /MANIFEST:EMBED
)

target_link_libraries(
	QtSimulator
	# ThirdParty.
	lvgl
	lua
	#lv_lib_png

	# Platform.
	GhostQtSimulator
	GhostFileSystemPatch

	# Drivers.
	GhostThread
	GhostMemoryManager
	GhostStandardClock
	GhostLog
	QtSimulatorScreen 
	
	GhostFileSystem
	GhostApps

)

