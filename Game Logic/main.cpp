#include "C:\Users\Zer0v\source\repos\Game\MessageBus\MessageBusNode.h"
#include "C:\Users\Zer0v\source\repos\Game\MessageBus\MessageBus.h"
#include "C:\Users\Zer0v\source\repos\Game\OpenGL\Window.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
class AudioDriver : public MessageBusNode {
public:
	void receiveMessage(Message* msg) {
		MessageBusNode::receiveMessage(msg); //Call same method signature from derived class. I.e,. the non over-written "recieveMessage" function. This function will merely output what the message is, and where it came from. 
		std::string event = msg->getMessage();

		if ((event == ("character_move_fwd")) || (event == ("character_move_left")) || (event == ("character_move_bottom")) || (event == ("character_move_right"))) {
			std::cout << "Object " << this << " plays footstep." << std::endl;
			this->sendMessage("play_footstep.wav");
		}
	}

	AudioDriver(): MessageBusNode() {}

};

class OpenGL_Shader : public MessageBusNode {
	
public:
	OpenGL_Shader() {}
	void receiveMessage(Message* msg) {
		MessageBusNode::receiveMessage(msg);
		std::string event = msg->getMessage();

		if (event == ("character_move_fwd")) {
			std::cout << "Object " << this << " draws character frame 20px higher." << std::endl;
		} else if (event == ("character_move_left")) {
			std::cout << "Object " << this << " draws character frame 20px left." << std::endl;
		}
		else if (event == ("character_move_right")) {
			std::cout << "Object " << this << " draws character frame 20px right." << std::endl;
		}
		else if (event == ("character_move_bottom")) {
			std::cout << "Object " << this << " draws character frame 20px lower." << std::endl;
		}
		else if (event == ("inventory_open")) {
			std::cout << "Object " << this << " draws inventory open." << std::endl;
		}
		else if (event == ("inventory_close")) {
			std::cout << "Object " << this << " clears inventory frame" << std::endl;
		}
	}

};

class InputDriver : public MessageBusNode {
	
public:
	InputDriver() {}
	void receiveMessage(Message* msg) {
		MessageBusNode::receiveMessage(msg);
		std::string event = msg->getMessage();
		//std::cout << "Object " << this << " recieves input: " << event.at(0) << std::endl;
		
	}
	

};

class Character : public MessageBusNode {
	
public:
	//Character() : MessageBusNode (){}
	void receiveMessage(Message* msg) {
		MessageBusNode::receiveMessage(msg);
		std::string event = msg->getMessage();

		if (event == "W_pressed") {
			this->sendMessage("character_move_fwd");
		}
		else if (event == "A_pressed") {
			this->sendMessage("character_move_left");
		}
		else if (event == "S_pressed") {
			this->sendMessage("character_move_bottom");
		}
		else if (event == "D_pressed") {
			this->sendMessage("character_move_right");
		}
		else if (event == "J_pressed") {
			this->sendMessage("inventory_open");
		}
		else if (event == "K_pressed") {
			this->sendMessage("inventory_close");
		}
	}

};

void *dummyLoop(InputDriver* inputHandler) {
	InputDriver input_handler = *inputHandler;
	while (true) {
		int num = (rand() % 6 + 1);

		if (num == 1) {
			input_handler.sendMessage("W_pressed");
		}
		else if (num == 2) {
			input_handler.sendMessage("A_pressed");
		}
		else if (num == 3) {
			input_handler.sendMessage("S_pressed");
		}
		else if (num == 4) {
			input_handler.sendMessage("D_pressed");
		}
		else if (num == 5) {
			input_handler.sendMessage("J_pressed");
		}
		else if (num == 6) {
			input_handler.sendMessage("K_pressed");
		}
		std::cout << num << "\n" << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

}

	int main() {
		MessageBus engineBus;
		//input_handler, audio_component, character_handler, render_engine;
		AudioDriver audio_component;
		OpenGL_Shader render_engine;
		InputDriver input_handler;
		Character character_handler;

		engineBus.addNodes(std::vector<MessageBusNode*>{
			&character_handler, &audio_component,
				&render_engine,
				&input_handler,
				});

		//Execute debug console and message bus
		thread thr1(dummyLoop,&input_handler);

		Window window;

		thr1.join();
		return 0;
	}


