cmake_minimum_required(VERSION 3.5)
project(TinySubMake)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(MAIN
	"src/main.cpp")

# "" = no name for this group
source_group("" FILES ${MAIN})

# configure tinyxml2 options: we want to build it as a shared library.
option(BUILD_SHARED_LIBS "build as shared library" OFF)
option(BUILD_STATIC_LIBS "build as static library" ON)
option(BUILD_TESTING "" OFF)

# add tinyxml2's CMakeLists
add_subdirectory(externals/tinyxml2)
# search headers here.
include_directories(externals/tinyxml2)

#PROJECT_NAME == TinySubMake.
add_executable(${PROJECT_NAME} ${MAIN})

#link tinyxml2 library
target_link_libraries(${PROJECT_NAME} tinyxml2_static)