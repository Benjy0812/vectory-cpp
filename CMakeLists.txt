cmake_minimum_required(VERSION 3.16)
project(vectory-cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wsign-compare)

include_directories(.)

add_executable(vectory-cpp
        main.cpp)