cmake_minimum_required(VERSION 2.4.3)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
cmake_policy(SET CMP0017 NEW)
#this line has to appear before 'PROJECT' in order to be able to disable incremental linking
SET(MSVC_INCREMENTAL_DEFAULT ON)

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
