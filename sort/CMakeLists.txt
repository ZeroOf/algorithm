cmake_minimum_required(VERSION 3.10)
project(sort)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(PROJECT_SOURCE_DIR src)

include_directories(${PROJECT_SOURCE_DIR})

FILE(GLOB_RECURSE SRC src/*.cpp src/*.c src/*.hpp src/*.h)

add_executable(sort ${SRC})