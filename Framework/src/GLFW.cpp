#include "glad.h"
#include <iostream>
#include <GLFW.h>


GLFW::GLFW()
{
    if (!glfwInit()) {
        std::cout << "Failed"<< std::endl;
    }

    window = glfwCreateWindow(640, 480, "Game", NULL, NULL);
    
    glfwMakeContextCurrent(window);
    gladLoadGL();

    while (!glfwWindowShouldClose(window))
    {
        //std::cout << glfwWindowShouldClose(window) << std::endl;
        
        glfwPollEvents();
        
    }
    glfwTerminate();
}

void GLFW::terminateWindow() {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
    
};

GLFWwindow* GLFW::getWindow() {
    return window;
}

