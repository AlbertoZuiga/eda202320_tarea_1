
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set the project name

project(sort
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(sort_ruts tests/sort_ruts.cpp src/sort.cpp src/utils.cpp)
target_include_directories(sort_ruts PUBLIC ${PROJECT_SOURCE_DIR}/include)

# add the executable
