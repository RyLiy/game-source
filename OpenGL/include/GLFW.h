#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLFW {
public:
	GLFW();
	void terminateWindow();
	GLFWwindow* getWindow();
private:
	GLFWwindow* window;

};