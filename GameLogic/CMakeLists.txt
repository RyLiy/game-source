cmake_minimum_required(VERSION 2.4.3)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
cmake_policy(SET CMP0017 NEW)
#this line has to appear before 'PROJECT' in order to be able to disable incremental linking
SET(MSVC_INCREMENTAL_DEFAULT ON)

PROJECT(GameLogic)

# Create library target and add sources
add_library(GameLogic src/Main.cpp)

target_link_libraries(GameLogic PRIVATE
 MessageBus

)
target_link_libraries(GameLogic PRIVATE OpenGL)