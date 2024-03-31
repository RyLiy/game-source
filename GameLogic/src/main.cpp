#include "glad.h"

 // GLFW is the one in the FRAMEWORK, not the native header. This must change.
#include "GLFW.h"


#include "MessageBus.h"
#include "../../Framework/include/Framework.h"

#include<iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <unordered_map>


/*
	Sample Logic class to test message bus functionality.
*/

enum class CharacterEvent {
	MoveForward,
	MoveLeft,
	MoveRight,
	MoveBottom,
	OpenInventory,
	CloseInventory
};

std::unordered_map<std::string, CharacterEvent> eventMap = {
	{"W_pressed", CharacterEvent::MoveForward},
	{"A_pressed", CharacterEvent::MoveLeft},
	{"S_pressed", CharacterEvent::MoveBottom},
	{"D_pressed", CharacterEvent::MoveRight},
	{"J_pressed", CharacterEvent::OpenInventory},
	{"K_pressed", CharacterEvent::CloseInventory}
};

class OpenGL_Shader : public MessageBusNode {

public:
	void receiveMessage(Message* msg) override {
		MessageBusNode::receiveMessage(msg);
		std::string event = msg->getMessage();

		auto iter = eventMap.find(event);
		if (iter != eventMap.end()) {
			handleCharacterEvent(iter->second);
		}
	}

private:
	void handleCharacterEvent(CharacterEvent event) {
		switch (event) {
		case CharacterEvent::MoveForward:
			handleCharacterMove("draws character frame 20px higher.");
			break;
		case CharacterEvent::MoveLeft:
			handleCharacterMove("draws character frame 20px left.");
			break;
		case CharacterEvent::MoveRight:
			handleCharacterMove("draws character frame 20px right.");
			break;
		case CharacterEvent::MoveBottom:
			handleCharacterMove("draws character frame 20px lower.");
			break;
		case CharacterEvent::OpenInventory:
			std::cout << "Object " << this << " draws inventory open." << std::endl;
			break;
		case CharacterEvent::CloseInventory:
			std::cout << "Object " << this << " clears inventory frame" << std::endl;
			break;
		}
	}

	void handleCharacterMove(const std::string& action) {
		std::cout << "Object " << this << ' ' << action << std::endl;
	}
};


class Character : public MessageBusNode {
public:
	void receiveMessage(Message* msg) override {
		MessageBusNode::receiveMessage(msg);
		std::string event = msg->getMessage();

		auto iter = eventMap.find(event);
		if (iter != eventMap.end()) {
			switch (iter->second) {
			case CharacterEvent::MoveForward:
				this->sendMessage("character_move_fwd");
				break;
			case CharacterEvent::MoveLeft:
				this->sendMessage("character_move_left");
				break;
			case CharacterEvent::MoveRight:
				this->sendMessage("character_move_right");
				break;
			case CharacterEvent::MoveBottom:
				this->sendMessage("character_move_bottom");
				break;
			case CharacterEvent::OpenInventory:
				this->sendMessage("inventory_open");
				break;
			case CharacterEvent::CloseInventory:
				this->sendMessage("inventory_close");
				break;
			}
		}
	}
};

//Game Window
GLFWwindow* window;
MessageBus engineBus;
InputDriver input_handler;


void keyCallback(GLFWwindow* wind, int key, int scancode, int action, int mods) {
	input_handler.key_callback(window, key, scancode, action, mods);
}

void inputLoop(InputDriver* inputHandler) {
	InputDriver input_handler = *inputHandler;

	/*
	Issue: callback has to be a static method or a non-member function. It cannot be an instanced variable. Nonstatic methods require a this pointer, which is a parameter that GLFW is not expecting.
	Callback has to send a message to the messagebus. Messagebus nodes have to be instanced types (objects). Therefore, callback has to send a message to the messagebus using an object (input_handler of type InputDriver), which was instantiated in a different class (main).
	The instanced object (input_handler) is a node on the message bus, and it's pointer/object variable has to be accessed from inside the callback to send a message. [I.e., input_handler->sendMessage(D_pressed)]

	EZ Solution: Use non member function as wrapper.
	*/
	while (!glfwWindowShouldClose(window)) {
		glfwSetKeyCallback(window, keyCallback);
	}
}

void terminateWindow() {
	glfwSetWindowShouldClose(window, GLFW_TRUE);

};


int main() {

	//input_handler, audio_component, character_handler, render_engine;
	Audio audio_driver;
	OpenGL_Shader render_engine;

	Character character_handler;

	//Loading the nodes onto the bus
	engineBus.addNodes(std::vector<MessageBusNode*>{
		&character_handler, & audio_driver,
			& render_engine,
			& input_handler
	});

	// if glfw fails to open.
	if (!glfwInit()) {
		std::cout << "Failed" << std::endl;
	}

	window = glfwCreateWindow(640, 480, "Game", NULL, NULL);

	glfwMakeContextCurrent(window);
	gladLoadGL();

	//Deploy input handler thread
	std::thread thr1(inputLoop, &input_handler);

	//Game Loop
	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(window);

	}

	thr1.join();
	//thr2.join();

	glfwTerminate();
	return 0;
}


