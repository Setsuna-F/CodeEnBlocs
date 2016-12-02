cmake_minimum_required(VERSION 2.8)
project(CodeEnBlocs)

include_directories("${CMAKE_SOURCE_DIR}/src")

file(GLOB_RECURSE SRC_LIST "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.hpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

add_executable(CodeEnBlocs ${SRC_LIST})

