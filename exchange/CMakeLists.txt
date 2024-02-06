cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_STANDARD 99)
project(exchange C)

file(GLOB_RECURSE src_files "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(exchange ${src_files})