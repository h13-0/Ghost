# The following are set after configuration is done:
# GHOST_MMGR_INCLUDE_DIRS

project(GhostMemoryManager)

# Generate libraries.
add_library(
	${PROJECT_NAME}
	STATIC
<<<<<<<< HEAD:Ghost/Drivers/MemoryManager/CMakeLists.txt
	"${PROJECT_SOURCE_DIR}/GhostMemoryManager.c"
========
	# GhostAppleInfograph
	"${PROJECT_SOURCE_DIR}/GhostAppleInfograph.c"

>>>>>>>> master:Ghost/App/NativeApplications/ThemeManager/Themes/CMakeLists.txt
)

# Set header paths.
set(
	GHOST_MMGR_INCLUDE_DIRS
	"${PROJECT_SOURCE_DIR}"
	CACHE PATH "Ghost log header file paths list."
)

target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC "${PROJECT_SOURCE_DIR}"
)
