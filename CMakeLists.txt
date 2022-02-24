cmake_minimum_required(VERSION 3.16)
project(cpp_hw6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")



include_directories(.)

add_executable(6.2 6_2.cpp)

add_executable(LockFreeStack LockFreeStack.h LockFreeStack.cpp)
target_link_libraries(LockFreeStack PRIVATE atomic)
