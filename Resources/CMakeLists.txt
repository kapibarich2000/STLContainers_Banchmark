cmake_minimum_required(VERSION 3.5)
project(Resources)

add_library(Test_Module Resources.cpp Resources.h)
set_target_properties(
        Test_Module PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CMAKE_CXX_FLAGS "-O0"
)
target_include_directories(Test_Module PUBLIC .)

add_subdirectory(Tests)

target_link_libraries(Test_Module Tests)



#___________________________________________________________#
