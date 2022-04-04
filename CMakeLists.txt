cmake_minimum_required(VERSION 3.21)
project(BasicRasterizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip # v1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()



add_executable(BasicRasterizer
        src/main.cpp
        src/camera/Camera.cpp)

target_include_directories(BasicRasterizer PRIVATE external)



target_link_libraries(
        BasicRasterizer
        gtest_main
)
include(GoogleTest)
gtest_discover_tests(BasicRasterizer)
