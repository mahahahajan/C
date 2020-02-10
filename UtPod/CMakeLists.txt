cmake_minimum_required(VERSION 3.14)
project(UtPod)

set(CMAKE_CXX_STANDARD 14)

add_executable(UtPod main.cpp UtPod.cpp UtPod.h Song.cpp Song.h)