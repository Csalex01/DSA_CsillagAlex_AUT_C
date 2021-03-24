cmake_minimum_required(VERSION 3.17)
project(Queue_Static C)

set(CMAKE_C_STANDARD 99)

add_executable(Queue_Static main.c queue.c queue.h menu.c menu.h)