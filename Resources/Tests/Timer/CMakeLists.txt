cmake_minimum_required(VERSION 3.5)
project(Timer)

add_library(Timer Timer.cpp Timer.h)

set_target_properties(
        Timer PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
target_include_directories(Timer PUBLIC .)
