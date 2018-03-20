cmake_minimum_required(VERSION 3.9)
project(lab_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_2 main.cpp GuardedStack.hpp ThreadGuard.cpp ThreadGuard.hpp BigData.cpp BigData.hpp)