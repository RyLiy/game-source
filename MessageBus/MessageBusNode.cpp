#include "Message.h"
#include "MessageBus.h"
#include <vector>
#include <iostream>
class MessageBusNode {
public:
	virtual void receiveMessage(Message *event) {
	//Every component could have a different way of processing events
		std::cout << "Object ID: " << this << " received: " << event->getMessage() << std::endl;
	}

	void sendMessage(Message msg) {
		bus.sendMessage(msg);
	}

	void setBus(MessageBus bus) {
		this->bus = bus;
	}

private:
	MessageBus bus;
	std::vector<Message> msgs;
};