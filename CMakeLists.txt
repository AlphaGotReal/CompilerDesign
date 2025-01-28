cmake_minimum_required(VERSION 3.10)
project(compiler C)

set(CMAKE_C_STANDARD 99)
add_executable(compiler src/main.c)

set(CMAKE_C_COMPILER gcc)
include_directories(include)

