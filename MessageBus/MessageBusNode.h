#pragma once
#include <vector>
#include <iostream>

class MessageBus;
class Message;

class MessageBusNode {
public:
	virtual void receiveMessage(Message *event);

	void sendMessage(std::string msg);

	void sendMessage(std::string msg, MessageBusNode* reciever);

	void sendMessage(std::string msg, std::vector<MessageBusNode*> recievers);

	void setBus(MessageBus *bus);

private:
	MessageBus *bus;
};