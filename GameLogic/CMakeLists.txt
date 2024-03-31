cmake_minimum_required(VERSION 3.4.0)

PROJECT(GameLogic)

# Create library target and add sources
add_library(GameLogic src/Main.cpp)

target_link_libraries(GameLogic PRIVATE
 MessageBus

)
target_link_libraries(GameLogic PRIVATE OpenGL)