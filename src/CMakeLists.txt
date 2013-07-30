
cmake_minimum_required (VERSION 2.8.0) 

project (Bubbles)

INCLUDE(${CMAKE_ROOT}/Modules/FindOpenGL.cmake)

add_subdirectory( ./game )
add_subdirectory( ./platform )
