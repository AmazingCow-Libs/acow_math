
cmake_minimum_required(VERSION 3.5)

##------------------------------------------------------------------------------
## Project Settings.
project(acow_math_goodies)

##------------------------------------------------------------------------------
## Sources.
add_library(acow_math_goodies
    acow/src/dummy.cpp
)

##------------------------------------------------------------------------------
## Include directories.
target_include_directories(acow_math_goodies PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

##------------------------------------------------------------------------------
## Dependencies.
target_link_libraries(acow_math_goodies LINK_PUBLIC acow_cpp_goodies)
