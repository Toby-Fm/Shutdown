cmake_minimum_required(VERSION 3.28)
project(Shutdown)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shutdown src/main.cpp
        src/include/main.hpp
        src/task.cpp
        src/include/task.hpp)
