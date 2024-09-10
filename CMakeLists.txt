cmake_minimum_required(VERSION 3.29)

project(rpg_kata_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add dependencies
#include(cmake/CPM.cmake)

add_subdirectory(src)
add_subdirectory(tests)
