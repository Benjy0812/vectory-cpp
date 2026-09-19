cmake_minimum_required(VERSION 4.3)
project(vectory-cpp)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -Wsign-compare)

include_directories(.)

add_executable(vectory-cpp
        main.cpp)