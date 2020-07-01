cmake_minimum_required(VERSION 3.14)
project(Simple_SQLite_clone)

set(CMAKE_CXX_STANDARD 17)

add_executable(Simple_SQLite_clone main.cpp Enums.h Statement.cpp Statement.h)