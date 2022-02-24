# The following variables are set after configuration is done:
# GHOST_LV_CONF_INCLUDE_DIRS

add_definitions(-DLV_CONF_INCLUDE_SIMPLE)

# Set header paths.
set(
	GHOST_LV_CONF_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}/Platforms/WindowsSimulator/LV_Conf"
)
