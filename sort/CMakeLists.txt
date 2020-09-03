cmake_minimum_required(VERSION 3.10)
project(sort)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(sort main.cpp SortTools.hpp Sort.hpp)