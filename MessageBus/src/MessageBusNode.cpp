#include "MessageBus.h"
#include <vector>
#include <iostream>


	// Define the behavior for receiving a message by a MessageBusNode
	void MessageBusNode::receiveMessage(Message *msg) {
		//Every component could have a different way of processing events
		std::cout << "Object " << this << " recieved: '" << msg->getMessage() << "' from Object " << msg->getSender() << std::endl;
		
	}

	// Send a message to the global space through the associated message bus
	void MessageBusNode::sendMessage(std::string msg) {
		std::cout << "Object " << this << " sent: '" << msg << "' to global space." << std::endl;
		bus->sendMessage(new Message(msg, this));

	}

	//Send a message to a specific recipient. Redudant, will be re-worked at a later date
	void MessageBusNode::sendMessage(std::string msg, MessageBusNode *reciever) {
		std::cout << "Object " << this << " sent: '" << msg << "' to Object " << reciever << std::endl;
		bus->sendMessage(new Message(msg, this, reciever));

	}

	// Send a message to a list of recipients. 
	void MessageBusNode::sendMessage(std::string msg, std::vector<MessageBusNode*> recievers) {
		std::cout << "Object " << this << " sent: '" << msg << "' to system space" << &recievers << std::endl;
		bus->sendMessage(new Message(msg, this, recievers));

	}

	// Set the associated message bus for this MessageBusNode
	void MessageBusNode::setBus(MessageBus *bus) {
		this->bus = bus;
	}


