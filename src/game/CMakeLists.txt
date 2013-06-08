
cmake_minimum_required (VERSION 2.8.4) 

project (bubbles_game)

include_directories (./../tools)
AUX_SOURCE_DIRECTORY( . SRC )

add_library(bubbleslib ${SRC})


