#pragma once
#include <optional>
#include <iostream>
#include "MessageBusNode.h"

class Message {
public:
	std::string systemSpace;
	std::optional<MessageBusNode*> systemComponent;
	Message(std::string EVENT, std::optional<std::string> system, std::optional<MessageBusNode*> component);
	Message(std::string EVENT);
	std::string getMessage();
private: //private to prevent modification
	std::string event;
};

