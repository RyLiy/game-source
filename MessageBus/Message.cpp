#include "MessageBus.h"
#include "MessageBusNode.h"
#include <optional>
#include <iostream>

	Message::Message(const std::string EVENT, std::optional<std::string> system, std::optional<MessageBusNode*> component) { //const variable to prevent modification of initialized event message.
		this->event = EVENT;

		if (system.has_value()) {
			systemSpace = system.value();
		 }

		if (component.has_value()) {
			systemComponent = component;
		}
	}

	std::string Message::getMessage() {
		return event;
	}



