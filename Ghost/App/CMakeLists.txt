# The following are set after configuration is done:
# GHOST_APP_INCLUDE_DIRS
# GHOST_APP_SOURCE_FILES
# GHOST_APP_LINK_LIBRARIES

# Add third-party dependence.
## lvgl
set(LVGL_PATH "${PROJECT_SOURCE_DIR}/App/ThirdParty/lvgl")
include(${PROJECT_SOURCE_DIR}/Tools/CMake/FindLVGL.cmake)

### 

## micropython


# Set header paths.
set(
	GHOST_APP_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}/App"
	"${PROJECT_SOURCE_DIR}/App/Log"
	"${GHOST_LVGL_INCLUDE_DIRS}"
)

message("${GHOST_LVGL_INCLUDE_DIRS}")

# Set source files.
set( 
	GHOST_APP_SOURCE_FILES
	"${PROJECT_SOURCE_DIR}/App/App.c"
	"${GHOST_LVGL_SOURCE_FILES}"
)

# Set link libraries.