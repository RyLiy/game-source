#pragma once
#include "C:\Users\Zer0v\source\repos\Game\MessageBus\MessageBusNode.h"
#include "C:\Users\Zer0v\source\repos\Game\MessageBus\MessageBus.h"
#include "C:\Users\Zer0v\source\repos\Game\OpenGL\GLFW.h"

class InputDriver : public MessageBusNode {
public:
	void receiveMessage(Message* msg);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

class Audio : public MessageBusNode {
public:
	void receiveMessage(Message* msg);

};