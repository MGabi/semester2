cmake_minimum_required(VERSION 3.10)
project(TestW11)

set(CMAKE_CXX_STANDARD 17)

add_executable(TestW11 main.cpp models/Canvas.cpp headers/Canvas.h models/Shape.cpp headers/Shape.h models/Rectangle.cpp headers/Rectangle.h models/Triangle.cpp headers/Triangle.h controller/Controller.cpp headers/Controller.h ui/UI.cpp headers/UI.h domain/Repo.cpp headers/Repo.h)