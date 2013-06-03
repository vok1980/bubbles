
cmake_minimum_required (VERSION 2.8.4) 

project (Bubbles)

INCLUDE(${CMAKE_ROOT}/Modules/FindOpenGL.cmake)

AUX_SOURCE_DIRECTORY( src SRC )

add_executable (bubbles ${SRC})


