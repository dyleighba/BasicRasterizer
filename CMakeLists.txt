cmake_minimum_required(VERSION 3.21)
project(BasicRasterizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BasicRasterizer
        src/main.cpp
        src/Camera.cpp)