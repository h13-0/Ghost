# - Find lvgl in ${LVGL_PATH}
# 
# The following variables are set after configuration is done:
# GHOST_LVGL_INCLUDE_DIRS
# GHOST_LVGL_SOURCE_FILES
# GHOST_LVGL_EXAMPLE_SOURCE_FILES
# GHOST_LVGL_LINK_LIBRARIES

if(${LVGL_PATH} STREQUAL "")
	message(FATAL_ERROR, "Please set variable LVGL_PATH.")
else()
	file(GLOB_RECURSE GHOST_LVGL_SOURCE_FILES ${LVGL_PATH}/src/*.c)
	file(GLOB_RECURSE GHOST_LVGL_EXAMPLE_SOURCE_FILES ${LVGL_PATH}/examples/*.c)
	set(GHOST_LVGL_INCLUDE_DIRS
		"${LVGL_PATH}"
		"${LVGL_PATH}/src"
	)
endif()
