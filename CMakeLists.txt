cmake_minimum_required(VERSION 2.4.3)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
cmake_policy(SET CMP0017 NEW)
#this line has to appear before 'PROJECT' in order to be able to disable incremental linking
SET(MSVC_INCREMENTAL_DEFAULT ON)

PROJECT(GAME_ENGINE)

# Add project's executable
add_executable(GameLogic GameLogic/src/main.cpp OpenGL/src/glad.c)

target_link_libraries(GameLogic PRIVATE OpenGL glfw MessageBus)

# Add subprojects
add_subdirectory(glfw-3.4)
add_subdirectory(Framework)
add_subdirectory(MessageBus)
add_subdirectory(OpenGL)
#add_subdirectory(GameLogic)



