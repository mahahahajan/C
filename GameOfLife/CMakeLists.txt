cmake_minimum_required(VERSION 3.14)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameOfLife life_driver.c life.h life.c)