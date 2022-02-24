# Project configs.
## Peripheral configs.

## Driver configs.
### Select ScreenDriver.
set(ScreenDriver "QT_GraphicsView")

### Select GyroscopeDriver.
set(IsGyroscopeEnable ON CACHE BOOL "" FORCE)
if(${IsGyroscopeEnable})
	set(GyroscopeDriver "Random")
endif()

### Select Compass.

## Application configs.
### Screen type.
#### Round or Rectangle.
set(ScreenType "Rectangle")

# find dependent packages.
find_package(pthreads CONFIG REQUIRED)
include_directories(${PThreads4W_INCLUDE_DIR})

# Build executable file.
## Add project modules.
include("${PROJECT_SOURCE_DIR}/App/CMakeLists.txt")
include("${PROJECT_SOURCE_DIR}/Drivers/CMakeLists.txt")

## Include submodules.
include("${CMAKE_CURRENT_LIST_DIR}/QT/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/LV_Conf/CMakeLists.txt")

## Set header paths.
include_directories(
	${GHOST_APP_INCLUDE_DIRS}

	${CMAKE_CURRENT_LIST_DIR}
	${GHOST_QT_INCLUDE_DIRS}
	${GHOST_LV_CONF_INCLUDE_DIRS}

)

## Add source files.
set(
	SOURCE_FILES
	${GHOST_APP_SOURCE_FILES}
	${CMAKE_CURRENT_LIST_DIR}/main.c
	${GHOST_QT_SOURCE_FILES}
)

# Compile executable file.
add_executable(WindowsSimulator ${SOURCE_FILES} )
target_link_libraries(WindowsSimulator ${GHOST_QT_LINK_LIBRARIES} ${PThreads4W_LIBRARY})
