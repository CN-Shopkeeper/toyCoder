cmake_minimum_required(VERSION 3.10)

project(toy_coder
  VERSION 0.1.0
  LANGUAGES CXX
  DESCRIPTION "a toy coder and decoder for English atricle")

include(cmake/copy.cmake)

set(PROJECT_NAME "TOY_CODER")

file(GLOB_RECURSE HEADER "src/*.hpp")
file(GLOB_RECURSE SRC "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC} ${HEADER})
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

CopyData(${PROJECT_NAME})