cmake_minimum_required(VERSION 3.22)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 main.cpp Token.h CommaAutomaton.h Scanner.h Scanner.cpp)
