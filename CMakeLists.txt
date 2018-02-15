cmake_minimum_required(VERSION 3.8)
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

#I assume to be working with visual studio (which kinda defeats the purpose of cmake, I know)
#and I want my generated project to have access to the /data folder (to load config files in this example).
#Setting VS_DEBUGGER_WORKING_DIRECTORY let me do that without copying the /data folder to the "out of source" dir (which can be very expensive)
#and without doing black magic (eg: environment variables or generated c++ string with the absolute path of the data folder).
#Note: we need to handle distribution, because people will also launch the .exe without visual studio, and the exe expect the /data folder to be "below him".
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
