#include "MessageBus.h"
#include "MessageBusNode.h"
#include "Message.h"

int main() {
	MessageBus bus;
	MessageBusNode input_handler, audio_component, character_handler, render_engine;

	bus.addNodes(std::vector<MessageBusNode*>{&input_handler, &audio_component, &character_handler, &render_engine});

	input_handler.sendMessage("W_PRESSED");

	character_handler.sendMessage("FOOTSTEP_NOISE", &audio_component);

	return 0;
}