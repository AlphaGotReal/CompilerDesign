cmake_minimum_required(VERSION 3.10)
project(compiler C)

set(CMAKE_C_STANDARD 99)

add_library(compiler_lib src/parser.c)
add_executable(compiler src/main.c)

target_link_libraries(compiler compiler_lib)

set(CMAKE_C_COMPILER gcc)
include_directories(include)

