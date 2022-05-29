#include "Message.h"
#include "MessageBus.h"
#include <vector>
#include <iostream>



	void MessageBusNode::receiveMessage(Message *msg) {
	//Every component could have a different way of processing events
		std::cout << "Object " << this << " recieved: '" << msg->getMessage() << "' from Object " << msg->getSender() << std::endl;
		
	}

	void MessageBusNode::sendMessage(std::string msg) {
		std::cout << "Object " << this << " sent: '" << msg << "' to global space." << std::endl;
		bus->sendMessage(new Message(msg, this));

	}


	void MessageBusNode::sendMessage(std::string msg, MessageBusNode *reciever) {
		std::cout << "Object " << this << " sent: '" << msg << "' to Object " << reciever << std::endl;
		bus->sendMessage(new Message(msg, this, reciever));

	}


	void MessageBusNode::sendMessage(std::string msg, std::vector<MessageBusNode*> recievers) {
		std::cout << "Object " << this << " sent: '" << msg << "' to system space" << &recievers << std::endl;
		bus->sendMessage(new Message(msg, this, recievers));

	}

	void MessageBusNode::setBus(MessageBus *bus) {
		this->bus = bus;
	}


