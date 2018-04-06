cmake_minimum_required(VERSION 3.10)
project(HWLab8_9)

set(CMAKE_CXX_STANDARD 17)

add_executable(HWLab8_9 main.cpp CoverageTests.cpp CoverageTests.h)

include(CodeCoverage.cmake)
APPEND_COVERAGE_COMPILER_FLAGS()