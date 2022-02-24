cmake_minimum_required(VERSION 3.16)
project(cpp_hw6)

set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")


set(CMAKE_CXX_STANDARD 20)


include_directories(.)

add_executable(cpp_hw6
        btree_orig.h
        LockFreeStack.h 6_2.cpp)
