#include "Message.h"
#include "MessageBus.h"
#include <vector>
#include <iostream>



	void MessageBusNode::receiveMessage(Message *event) {
	//Every component could have a different way of processing events
		std::cout << "Object ID: " << this << " received: " << event->getMessage() << std::endl;
		
	}

	void MessageBusNode::sendMessage(Message *msg) {
		bus->sendMessage(msg);
	}

	void MessageBusNode::setBus(MessageBus *bus) {
		this->bus = bus;
	}


