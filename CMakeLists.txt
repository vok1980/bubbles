
cmake_minimum_required (VERSION 2.8.4) 

project (Bubbles)

INCLUDE(${CMAKE_ROOT}/Modules/FindOpenGL.cmake)

add_subdirectory( ./src/game )
add_subdirectory( ./src/starter.win32 )



