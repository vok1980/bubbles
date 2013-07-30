
cmake_minimum_required (VERSION 2.8.0) 

project (bubbles.android)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

include_directories (./../game)
include_directories (./../tools)

AUX_SOURCE_DIRECTORY( ./Bubbles/jni SRC )

add_library (bubbles SHARED ${SRC})
target_link_libraries(bubbles bubbleslib)

