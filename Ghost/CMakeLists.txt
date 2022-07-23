cmake_minimum_required(VERSION 3.0)

# Project informations.
project(Ghost VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Specify parameters on the command line.
set(Platform_Config "AutoSelect" CACHE STRING "Path of CMakeLists.txt used by the target platform." FORCE)

# Set header paths.
include_directories("${PROJECT_SOURCE_DIR}")

# Select platform profile.
if(${Platform_Config} STREQUAL "AutoSelect")
	if(WIN32 OR UNIX)
		message(STATUS "Auto select profile: " ${PROJECT_SOURCE_DIR}/Platforms/QtSimulator/CMakeLists.txt " to build.")
		include(${PROJECT_SOURCE_DIR}/Platforms/QtSimulator/CMakeLists.txt)
	#elseif(UNIX)
		# include
	endif()
else()
	include(${Platform_Config})
endif()
