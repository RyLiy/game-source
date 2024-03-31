#include "Framework.h"
/*
Input test class for messagebus.
*/

void InputDriver::receiveMessage(Message* msg) {
	MessageBusNode::receiveMessage(msg);
	std::string event = msg->getMessage();
}


int times = 0;
void InputDriver::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_W) { //&& action == GLFW_PRESS
		this->sendMessage("W_pressed");
		std::cout << "sent W" << std::endl;
	}
	else if (key == GLFW_KEY_A) {
		this->sendMessage("A_pressed");
	}
	else if (key == GLFW_KEY_S) {
		this->sendMessage("S_pressed");
	}
	else if (key == GLFW_KEY_D) {
		this->sendMessage("D_pressed");
	}
	else if (key == GLFW_KEY_J && action == GLFW_PRESS) {
		this->sendMessage("J_pressed");
	}
	else if (key == GLFW_KEY_K && action == GLFW_PRESS) {
		this->sendMessage("K_pressed");
	}
	times++;
	std::cout << "Key: " << key << " | " << times << std::endl;
}



