#pragma once
#include <vector>
#include <iostream>

class MessageBus;
class Message;

class MessageBusNode {
public:
	virtual void receiveMessage(Message *event);

	void sendMessage(Message *msg);

	void setBus(MessageBus *bus);

private:
	MessageBus *bus;
};