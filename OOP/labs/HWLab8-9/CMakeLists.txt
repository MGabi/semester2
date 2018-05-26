cmake_minimum_required(VERSION 3.10)
project(HWLab8_9)

set(CMAKE_CXX_STANDARD 17)

add_executable(HWLab8_9 main.cpp CoverageTests.cpp headers/CoverageTests.h ui/UI.cpp headers/UI.h controllers/Controller.cpp headers/Controller.h domain/CSVRepo.cpp headers/CSVRepo.h domain/models/Tutorial.cpp headers/Tutorial.h utils/Utils.cpp headers/Utils.h domain/Repo.cpp headers/Repo.h validators/Validators.cpp headers/Validators.h domain/models/Duration.cpp headers/Duration.h domain/Playlist.cpp headers/Playlist.h headers/UndoAction.h utils/UndoAdd.cpp headers/UndoAdd.h utils/UndoRemove.cpp headers/UndoRemove.h utils/UndoUpdate.cpp headers/UndoUpdate.h)

include(CodeCoverage.cmake)
APPEND_COVERAGE_COMPILER_FLAGS()