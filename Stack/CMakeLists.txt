cmake_minimum_required(VERSION 3.14)
project(Stack C)

set(CMAKE_C_STANDARD 99)

add_library(Stack library.c library.h stack_ll.c stack_ll.h driver.c)