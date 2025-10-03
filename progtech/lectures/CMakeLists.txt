cmake_minimum_required(VERSION 3.21)
project(lectures)

set(CMAKE_CXX_STANDARD 14)

add_executable(lectures main.cpp Person.cpp "lecture 2.cpp" "lecture 3.cpp" "lecture 4.0.cpp" container.cpp)
