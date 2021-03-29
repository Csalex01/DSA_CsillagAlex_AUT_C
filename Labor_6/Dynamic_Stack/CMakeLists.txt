cmake_minimum_required(VERSION 3.17)
project(Dynamic_Stack C)

set(CMAKE_C_STANDARD 99)

add_executable(Dynamic_Stack main.c stack.c stack.h)