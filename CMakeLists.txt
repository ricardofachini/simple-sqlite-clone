cmake_minimum_required(VERSION 3.28)
project(sqlite_clone)

set(CMAKE_CXX_STANDARD 17)

add_executable(sqlite_clone main.cpp
        main.h
        buffer.h
        btree.h)
