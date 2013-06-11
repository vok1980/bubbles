
cmake_minimum_required (VERSION 2.8.0) 

project (bubbles_game)

add_definitions(-DNOMINMAX)

include_directories ( ./../tools )
include_directories ( ./visitors )
include_directories ( ./objects )
include_directories ( . )

AUX_SOURCE_DIRECTORY( ./visitors SRC_VIS )
AUX_SOURCE_DIRECTORY( ./objects SRC_OBJ )
AUX_SOURCE_DIRECTORY( . SRC )

source_group("Source Files\\visitors" FILES ${SRC_VIS})
source_group("Source Files\\objects" FILES ${SRC_OBJ})


add_library(bubbleslib 
					${SRC} 
					${SRC_VIS}
					${SRC_OBJ}
)


