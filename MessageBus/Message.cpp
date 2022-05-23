#include "MessageBus.h"
#include "MessageBusNode.h"
#include <optional>
#include <iostream>
class Message {
public:
	std::string systemSpace;
	std::optional<MessageBusNode> systemComponent;
	Message::Message(const std::string EVENT, std::optional<std::string> system, std::optional<MessageBusNode> component) { //const variable to prevent modification of initialized event message.
		this->event = EVENT;

		if (system.has_value()) {
			systemSpace = system.value();
		 }

		if (component.has_value()) {
			systemComponent = component.value();
		}
	}

	std::string getMessage() {
		return event;
	}
private: //private to prevent modification
	std::string event;
};

