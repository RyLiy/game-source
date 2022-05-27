#pragma once
#include <vector>
#include <map>
#include <optional>
#include <iostream>
#include <algorithm>
#include "MessageBusNode.h"
#include "Message.h"
using namespace std;
class MessageBus {

public:
	void addNode(MessageBusNode node);
	void sendMessage(Message *msg);
	void notify();
	//void addNode(MessageBusNode node, std::optional<std::string> nodeClass);

private:
	std::vector<MessageBusNode> nodes;
	std::vector<Message*> messageQueue;

	//Creates a map structure to classify what system space a node belongs to. (E.g., does the node belong to the input system, render system, game-logic system, etc.) 
	map<std::string, std::vector<MessageBusNode>> nodeClass;
};