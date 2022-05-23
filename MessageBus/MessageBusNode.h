#pragma once
#include <vector>
#include <iostream>
//#include "MessageBus.h"
#include "MessageBusNode.h"

class MessageBus;
class Message;

class MessageBusNode {
public:
	virtual void receiveMessage(Message *event);

	void sendMessage(Message *msg);

	void setBus(MessageBus *bus);

private:
	MessageBus *bus;
	std::vector<Message*> msgs;
};