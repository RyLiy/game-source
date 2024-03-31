#pragma once
#include "../../MessageBus/include/MessageBus.h"
#include "GLFW/glfw3.h"
class InputDriver : public MessageBusNode {
public:
	void receiveMessage(Message* msg);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

class Audio : public MessageBusNode {
public:
	void receiveMessage(Message* msg);

};