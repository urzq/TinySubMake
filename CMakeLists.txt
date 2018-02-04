cmake_minimum_required(VERSION 3.5)
project(TinySubMake)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(MAIN
	"src/main.cpp")

# "" = no name for this group
source_group("" FILES ${MAIN})

add_executable(${PROJECT_NAME} ${MAIN})