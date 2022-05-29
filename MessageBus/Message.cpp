#include "MessageBus.h"
#include "MessageBusNode.h"
#include <optional>
#include <iostream>


Message::Message(std::string event, MessageBusNode* sender, MessageBusNode* component) {
	this->event = event;
	std::vector<MessageBusNode*> cList{ component };
	componentList = cList;
	this->sender = sender;
}

Message::Message(std::string event, MessageBusNode* sender, std::vector<MessageBusNode*> components) {
	this->event = event;
	componentList = components;
	this->sender = sender;
}


Message::Message(std::string event, MessageBusNode *sender) {
	this->event = event;
	this->sender = sender;
}

	std::string Message::getMessage() {
		return event;
	}

	MessageBusNode* Message::getSender() {
		return sender;
	}
	
	std::vector<MessageBusNode*> Message::getRecipients() {
		return componentList;
	}


