# Select ScreenDriver
set(ScreenDriver "" CACHE STRING "Path of touch screen driver." FORCE)

if(${ScreenDriver} STREQUAL "")
	message(FATAL_ERROR "No ScreenDriver selected, please check your platform configs.")
else()
	# Add compile target.	
	include("${PROJECT_SOURCE_DIR}/Drivers/Screen/${ScreenDriver}/CMakeLists.txt")
endif()
