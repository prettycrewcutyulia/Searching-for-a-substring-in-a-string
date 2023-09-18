cmake_minimum_required(VERSION 3.24)
project(Program)

set(CMAKE_CXX_STANDARD 17)

add_executable(Program main.cpp native.cpp algorithm.h kmp.cpp kmpBest.cpp generation.h generation.cpp rabinKarp.cpp)
