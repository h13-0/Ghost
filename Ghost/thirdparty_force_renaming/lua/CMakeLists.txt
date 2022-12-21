# The following are set after configuration is done:
# LUA_SOURCE_FILES
# LUA_INCLUDE_DIRS

project(lua)

# Add source files to variables.
aux_source_directory("${PROJECT_SOURCE_DIR}" LUA_SOURCE_FILES) 
## Remove useless files.
list(
	REMOVE_ITEM LUA_SOURCE_FILES
	"${PROJECT_SOURCE_DIR}/ThirdParty/lua/lua.c"
)

# Generate libraries.
add_library(
	${PROJECT_NAME} 
	STATIC 
	${LUA_SOURCE_FILES}
)

# Link libraries.
target_link_libraries(
	${PROJECT_NAME}
)

# Set header paths.
set(
	LUA_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "lua header file paths list."
)

include_directories(
	"${LUA_INCLUDE_DIRS}"
)
