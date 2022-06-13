#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "C:\Users\Zer0v\source\repos\Game\OpenGL\Window.h"

#include "C:\Users\Zer0v\source\repos\Game\MessageBus\MessageBusNode.h"
#include "C:\Users\Zer0v\source\repos\Game\MessageBus\MessageBus.h"


Window::Window()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(640, 480, "Game", NULL, NULL);

    while (!glfwWindowShouldClose(window))
    {

        //Need to constantly poll for events, or the window will be unresponsive
        glfwPollEvents();
    }
    glfwTerminate();
}

GLFWwindow* Window::getWindow() {
    return window;
}

//int main() {
//    Window window;
//    return 0;
//}