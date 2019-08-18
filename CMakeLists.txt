# Minimum CMake required
cmake_minimum_required(VERSION 3.5)

project(Algorithm CXX)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-O3)

find_package (Threads)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(googletest)

add_subdirectory(FindMedia)
