project(Screen)

# Select ScreenDriver
#set(ScreenDriver "" CACHE STRING "Path of touch screen driver." FORCE)

if("${ScreenDriver}" STREQUAL "")
	message(FATAL_ERROR "No ScreenDriver selected, please check your platform configs.")
else()
	# Add compile target.
	add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/${ScreenDriver}")
	#target_link_libraries("${PROJECT_NAME}" PRIVATE "${ScreenDriver}")
endif()
