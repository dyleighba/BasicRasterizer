cmake_minimum_required(VERSION 3.21)
project(BasicRasterizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_NAME BasicRasterizer)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip # v1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()



add_executable(${EXECUTABLE_NAME}
        src/main.cpp
        src/camera/Camera.cpp)

target_include_directories(${EXECUTABLE_NAME} PRIVATE external)



target_link_libraries(
        ${EXECUTABLE_NAME}
        gtest_main
)
include(GoogleTest)
gtest_discover_tests(${EXECUTABLE_NAME})



# Detect and add SFML
set(SFML_DIR external/SFML/lib/cmake/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()