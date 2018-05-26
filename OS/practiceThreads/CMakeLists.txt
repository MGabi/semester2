cmake_minimum_required(VERSION 3.10)
project(practiceThreads C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-pthread")

add_executable(practiceThreads main.c)