cmake_minimum_required(VERSION 3.4)
project(chess_lists)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(chess_lists ${SOURCE_FILES})