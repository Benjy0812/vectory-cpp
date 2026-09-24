cmake_minimum_required(VERSION 3.16)
project(vectory-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default to Release for single-config generators (Makefiles, Ninja)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

add_executable(vectory-cpp main.cpp)

if(MSVC)
    target_compile_options(vectory-cpp PRIVATE /W4)
else()
    target_compile_options(vectory-cpp PRIVATE -Wall -Wextra -Wsign-compare)
endif()