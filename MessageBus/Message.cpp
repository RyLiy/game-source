#include "MessageBus.h"
#include "MessageBusNode.h"
#include <optional>
#include <iostream>

Message::Message(std::string EVENT, std::optional<std::string> system, std::optional<MessageBusNode*> component) { 
	this->event = EVENT;

	if (system.has_value()) {
		systemSpace = system.value();
	}

	if (component.has_value()) {
		systemComponent = component;
	}
}


Message::Message(std::string EVENT) {
	this->event = EVENT;
}

	std::string Message::getMessage() {
		return event;
	}



