cmake_minimum_required(VERSION 3.4.0)

PROJECT(Framework)

# Add all source files
set(SOURCES
    src/audio.cpp
    src/GLFW.cpp
    src/input.cpp
)

# Create library target and add sources
add_library(Framework ${SOURCES})

target_link_libraries(Framework PRIVATE OpenGL glfw MessageBus)

target_include_directories(Framework PUBLIC include)
