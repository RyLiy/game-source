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
	void sendMessage(Message msg);
	

void notify();


void addNode(MessageBusNode node, std::optional<std::string> nodeClass);
};