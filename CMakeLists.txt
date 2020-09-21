cmake_minimum_required(VERSION 3.18)
project(sorts)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(sorts
        src/DynArray.cpp
        src/main.cpp)
