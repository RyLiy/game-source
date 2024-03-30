#pragma once
#include <optional>
#include <iostream>
#include "MessageBusNode.h"

class Message {
public:
	Message(std::string event, MessageBusNode* sender, MessageBusNode* component);
	Message(std::string event, MessageBusNode* sender, std::vector<MessageBusNode*> component);
	Message(std::string event, MessageBusNode *sender);
	std::string getMessage();
	MessageBusNode* getSender();
	std::vector<MessageBusNode*> getRecipients();
private: //private to prevent modification
	std::string event;
	MessageBusNode *sender;
	std::vector<MessageBusNode*> componentList;
};

