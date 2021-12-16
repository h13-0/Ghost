# Select ScreenDriver
set(ScreenDriver "" CACHE STRING "Path of touch screen driver." FORCE)

if(${ScreenDriver} STREQUAL "")
	# Add compile target.
	add_subdirectory(${ScreenDriver})
else()
	message(FATAL_ERROR "No ScreenDriver selected, please check your platform configs.")
endif()
