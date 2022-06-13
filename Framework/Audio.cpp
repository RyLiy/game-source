#include "C:\Users\Zer0v\source\repos\Game\MessageBus\MessageBusNode.h"
#include "C:\Users\Zer0v\source\repos\Game\MessageBus\MessageBus.h"

class Audio : public MessageBusNode {
public:
	void receiveMessage(Message* msg) {
		MessageBusNode::receiveMessage(msg);
		std::string event = msg->getMessage();

	}

	Audio() : MessageBusNode() {}

};
