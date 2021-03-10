cmake_minimum_required(VERSION 3.17)
project(matrix_feladat C)

set(CMAKE_C_STANDARD 99)

add_executable(matrix_feladat main.c matrix_functions.c matrix_functions.h)