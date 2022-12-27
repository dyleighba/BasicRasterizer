cmake_minimum_required(VERSION 3.21)
project(BasicRasterizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_NAME BasicRasterizer)

include(FetchContent)
FetchContent_Declare(
        SFML
        URL https://github.com/SFML/SFML/releases/download/2.5.1/SFML-2.5.1-sources.zip
        URL_HASH MD5=8533b22888102b4f0883311385fb1c71
)
FetchContent_MakeAvailable(SFML)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

set(HEADERS
        src/camera/CameraAttributes.h
        src/draw/Colour.h
        src/draw/Rect.h
        src/draw/Triangle.h
        src/geometry/Triangle3D.h
        src/input/Input.h
        src/output/Output.h)

set(SOURCES
        src/main.cpp
        src/camera/Camera.cpp
        src/draw/DrawUtility.cpp
        src/frame/Frame.cpp
        src/geometry/Geometry.cpp
        src/input/InputPrimitive.cpp
        src/output/OutputSFML.cpp)

add_executable(${EXECUTABLE_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${EXECUTABLE_NAME} PRIVATE src)
target_include_directories(${EXECUTABLE_NAME} PRIVATE external)

target_link_libraries(BasicRasterizer sfml-graphics)