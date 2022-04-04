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

set(HEADERS
        src/output/Output.h)

set(SOURCES
        src/main.cpp
        src/camera/Camera.cpp
        src/frame/Frame.cpp
        src/geometry/Geometry.cpp
        src/input/Input.cpp
        src/output/OutputSFML.cpp)

add_executable(${EXECUTABLE_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${EXECUTABLE_NAME} PRIVATE src)
target_include_directories(${EXECUTABLE_NAME} PRIVATE external)




target_link_libraries(
        ${EXECUTABLE_NAME}
        gtest_main
)
include(GoogleTest)
#gtest_discover_tests(${EXECUTABLE_NAME} PROPERTIES TIMEOUT 600)



if (WIN32)
    set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
endif ()

find_package(SFML 2 COMPONENTS graphics REQUIRED)
target_link_libraries(BasicRasterizer sfml-graphics)

if (WIN32)
    add_custom_command(TARGET BasicRasterizer POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/SFML/bin"
            $<TARGET_FILE_DIR:BasicRasterizer>
            COMMENT "Copying SFML dlls..."
            )
endif ()