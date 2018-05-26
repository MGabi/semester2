cmake_minimum_required(VERSION 3.10)
project(TestW8)

set(CMAKE_CXX_STANDARD 17)

add_executable(TestW8 main.cpp domain/models/MemoryAllocation.cpp headers/MemoryAllocation.h domain/RepoMemory.cpp headers/RepoMemory.h controllers/Controller.cpp headers/Controller.h ui/UI.cpp headers/UI.h)

include(CodeCoverage.cmake)
APPEND_COVERAGE_COMPILER_FLAGS()