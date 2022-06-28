# The following are set after configuration is done:
# GHOST_CMP_LOG_INCLUDE_DIRS

project(GhostCmpLog)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
	"${PROJECT_SOURCE_DIR}/GhostLog.c"
)

# Set header paths.
set(
	GHOST_CMP_LOG_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost log header file paths list."
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)
