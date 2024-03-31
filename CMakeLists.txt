cmake_minimum_required(VERSION 3.4.0)

PROJECT(GAME_ENGINE)

# Add project's executable
add_executable(GameLogic GameLogic/src/main.cpp OpenGL/src/glad.c)

target_link_libraries(GameLogic PRIVATE OpenGL glfw Framework MessageBus)

# Add subprojects
add_subdirectory(glfw-3.4)
add_subdirectory(Framework)
add_subdirectory(MessageBus)
add_subdirectory(OpenGL)
#add_subdirectory(GameLogic)



