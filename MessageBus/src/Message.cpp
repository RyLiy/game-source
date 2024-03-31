#include "MessageBus.h"
#include <optional>
#include <iostream>

// Constructor for a message with a single recipient
Message::Message(std::string event, MessageBusNode* sender, MessageBusNode* component) {
	this->event = event;
	std::vector<MessageBusNode*> cList{ component };
	componentList = cList;
	this->sender = sender;
}

// Constructor for a message with multiple recipients
Message::Message(std::string event, MessageBusNode* sender, std::vector<MessageBusNode*> components) {
	this->event = event;
	componentList = components;
	this->sender = sender;
}

// Constructor for a message with no specific recipient component
Message::Message(std::string event, MessageBusNode* sender) {
	this->event = event;
	this->sender = sender;
}

// Retrieve the event string of the message
std::string Message::getMessage() {
	return event;
}

// Retrieve the sender of the message
MessageBusNode* Message::getSender() {
	return sender;
}

// Retrieve the list of recipient components of the message
std::vector<MessageBusNode*> Message::getRecipients() {
	return componentList;
}


