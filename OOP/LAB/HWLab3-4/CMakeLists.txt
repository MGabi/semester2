cmake_minimum_required(VERSION 3.9)
project(HWLab3_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(HWLab3_4 main.c ui/console.c headers/console.h domain/entities/dynamic_array.c headers/dynamic_array.h domain/entities/country.c headers/country.h repository/repository.c headers/repository.h controller/controller.c controller/controller.h)