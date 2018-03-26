cmake_minimum_required(VERSION 3.9)
project(HWLab5_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(HWLab5_6 main.cpp
        domain/Tutorial.cpp
        domain/Tutorial.h
        domain/PlayList.cpp
        domain/PlayList.h
        domain/DynamicVector.cpp
        domain/DynamicVector.h
        repository/Repository.cpp
        repository/Repository.h
        service/Controller.cpp
        service/Controller.h
        ui/UI.cpp
        ui/UI.h)