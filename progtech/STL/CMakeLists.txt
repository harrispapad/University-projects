cmake_minimum_required(VERSION 3.21)
project(STL)

set(CMAKE_CXX_STANDARD 14)

add_executable(STL main.cpp array.cpp Vector.cpp list.cpp set.cpp map.cpp)
