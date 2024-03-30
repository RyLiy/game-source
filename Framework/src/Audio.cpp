#include "../Framework/Framework.h"

/*
Audio test class for messagebus.
*/

	void Audio::receiveMessage(Message* msg) {
		MessageBusNode::receiveMessage(msg); //Call same method signature from derived class. I.e,. the non over-written "recieveMessage" function. This function will merely output what the message is, and where it came from. 
		std::string event = msg->getMessage();

		if ((event == ("character_move_fwd")) || (event == ("character_move_left")) || (event == ("character_move_bottom")) || (event == ("character_move_right"))) {
			std::cout << "Object " << this << " plays footstep.way" << std::endl;
			//this->sendMessage("play_footstep.wav");
		}
	}
