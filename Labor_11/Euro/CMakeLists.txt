cmake_minimum_required(VERSION 3.17)
project(Euro C)

set(CMAKE_C_STANDARD 99)

add_executable(Euro main.c Heap.c Heap.h Exchange.c Exchange.h)