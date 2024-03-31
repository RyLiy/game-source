cmake_minimum_required(VERSION 3.4.0)


PROJECT(OpenGL)

# Add all source files
set(SOURCES
    src/Model.cpp
    src/WorldObject.cpp
)

# Create library target and add sources
add_library(OpenGL ${SOURCES})

target_include_directories(OpenGL PUBLIC include)