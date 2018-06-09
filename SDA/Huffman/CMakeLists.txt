cmake_minimum_required(VERSION 3.10)
project(Huffman)

set(CMAKE_CXX_STANDARD 17)

add_executable(Huffman main.cpp adts/BinaryTree.cpp headers/BinaryTree.h adts/PriorityQueue.cpp headers/PriorityQueue.h adts/PreorderIterator.cpp headers/PreorderIterator.h)

include(CodeCoverage.cmake)
APPEND_COVERAGE_COMPILER_FLAGS()