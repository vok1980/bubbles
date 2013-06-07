
cmake_minimum_required (VERSION 2.8.4) 

project (bubbles.win32)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

include_directories (./../game)

AUX_SOURCE_DIRECTORY( . SRC )

add_executable (bubbles ${SRC})
target_link_libraries(bubbles bubbleslib)
