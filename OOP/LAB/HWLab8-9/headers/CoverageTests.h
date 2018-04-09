//
// Created by mgabi on 06.04.2018.
//
#pragma once
#include "cassert"

class CoverageTests {
public:
    CoverageTests() = default;
    void startTesting();

    void testTutorial();

    void testDuration();

    void testCSVRepo();
};
