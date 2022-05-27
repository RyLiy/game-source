#include "MessageBus.h"
#include "MessageBusNode.h"
#include "Message.h"

int main() {
	MessageBus bus;
	MessageBusNode testAxel;
	bus.addNode(testAxel);
	testAxel.setBus(&bus);

	testAxel.sendMessage(new Message("EVENT triggered"));


	return 0;
}