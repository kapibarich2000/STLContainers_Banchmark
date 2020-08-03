cmake_minimum_required(VERSION 3.5)
project(Benchmark_std_containers VERSION 0.2.2)

add_subdirectory(Resources)

add_executable(Benchmarks main.cpp)

set_target_properties(
        Benchmarks PROPERTIES
        CMAKE_CXX_FLAGS "-O0"
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(Benchmarks Test_Module)
