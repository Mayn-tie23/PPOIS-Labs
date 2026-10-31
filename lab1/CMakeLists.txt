
cmake_minimum_required(VERSION 3.16)

project(PPOIS_Lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1
    Lab1_UI.cpp
    set/Set.cpp
    polynomial/Polynomial.cpp
)
enable_testing()
add_executable(SetTests tests/SetTests.cpp set/Set.cpp)
add_test(NAME SetTests COMMAND SetTests)
add_executable(PolynomialTests
    tests/PolynomialTests.cpp
    polynomial/Polynomial.cpp
)

add_test(NAME PolynomialTests COMMAND PolynomialTests)