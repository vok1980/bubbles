
cmake_minimum_required (VERSION 2.8.0) 

project (platform)

if(WIN32)
add_subdirectory( ./win32 )
endif(WIN32)

if (ANDROID)
add_subdirectory( ./android )
endif(ANDROID)
