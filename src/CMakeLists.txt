
cmake_minimum_required (VERSION 2.8.0) 

project (Bubbles)

INCLUDE(${CMAKE_ROOT}/Modules/FindOpenGL.cmake)

add_subdirectory( ./src/game )

if(WIN32)
add_subdirectory( ./src/starter.win32 )
endif(WIN32)

if (ANDROID)
add_subdirectory( ./src/starter.android )
endif(ANDROID)
