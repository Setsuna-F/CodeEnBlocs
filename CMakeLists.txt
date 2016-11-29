cmake_minimum_required(VERSION 2.8)
project(CodeEnBlocs)

include_directories("${CMAKE_SOURCE_DIR}/src")
#include_directories("${CMAKE_SOURCE_DIR}/src/model")
#include_directories("${CMAKE_SOURCE_DIR}/src/view")
#include_directories("${CMAKE_SOURCE_DIR}/src/controller")

file(GLOB_RECURSE SRC_SRC_LIST "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.h")
#file(GLOB_RECURSE MODEL_SRC_LIST "${CMAKE_SOURCE_DIR}/src/model/*.cpp" "${CMAKE_SOURCE_DIR}/src/model/*.h")
#file(GLOB_RECURSE VIEW_SRC_LIST "${CMAKE_SOURCE_DIR}/src/view/*.cpp" "${CMAKE_SOURCE_DIR}/src/view/*.h")
#file(GLOB_RECURSE CONTROLLER_SRC_LIST "${CMAKE_SOURCE_DIR}/src/controller/*.cpp" "${CMAKE_SOURCE_DIR}/src/controller/*.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

#add_executable(CodeEnBlocs main.cpp)
add_executable(CodeEnBlocs ${SRC_SRC_LIST})

#add_executable(CodeEnBlocs ${SRC_SRC_LIST} ${MODEL_SRC_LIST} ${VIEW_SRC_LIST} ${CONTROLLER_SRC_LIST})

