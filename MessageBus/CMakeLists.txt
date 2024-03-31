cmake_minimum_required(VERSION 3.4.0)


PROJECT(MessageBus)

# Add all source files
set(SOURCES
    src/MessageBus.cpp
    src/MessageBusNode.cpp
    src/Message.cpp
)

# Create library target and add sources
add_library(MessageBus ${SOURCES})

target_include_directories(MessageBus PUBLIC include)