#pragma once
#include <optional>
#include <iostream>
#include "MessageBusNode.h"

class Message {
public:
	std::string systemSpace;
	std::optional<MessageBusNode> systemComponent;
	Message(const std::string EVENT, std::optional<std::string> system, std::optional<MessageBusNode> component);

	std::string getMessage();
private: //private to prevent modification
	std::string event;
};

