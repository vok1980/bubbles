
cmake_minimum_required (VERSION 2.8.4) 

project (bubbles_game)

INCLUDE(${CMAKE_ROOT}/Modules/FindOpenGL.cmake)

AUX_SOURCE_DIRECTORY( . SRC )

add_library(bubbleslib ${SRC})


