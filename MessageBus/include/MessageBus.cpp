#include "Message.h"
#include "MessageBus.h"
#include "MessageBusNode.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iostream>

	// Add a single node to the message bus
	void MessageBus::addNodes(MessageBusNode *node) {
		nodes.push_back(node);
		syncBusNode(std::vector<MessageBusNode*>{node});
	}

	// Add an array of nodes to the message bus
	void MessageBus::addNodes(std::vector<MessageBusNode*> nodeList) {
		this->nodes.insert(nodes.end(), nodeList.begin(), nodeList.end());
		syncBusNode(nodeList);
	}

	// Set the current message bus as the bus for all nodes in the given array
	void MessageBus::syncBusNode(std::vector<MessageBusNode*> nodeList) { 
		for (auto node : nodeList) {
			node->setBus(this);
		}
	}

	// Add a message to the message queue and trigger the notification process
	void MessageBus::sendMessage(Message *msg) {
		messageQueue.push_back(msg);
		notify();
	}

	// Dispatch messages accordingly
	void MessageBus::notify() {
		// Iterates through entire message queue
		for (auto message: messageQueue) { 
			Message *msg = messageQueue.back(); 
			
			messageQueue.pop_back();

			// if the message isn't directed towards a particular recipient (system space or component)
			if ((msg->getRecipients().empty())) { 

				// send the message to all nodes in the bus. I.e., all system spaces -- 'the global space'.
				for (auto iterate = nodes.begin(); iterate != nodes.end(); iterate++) { 
					if ((*iterate) != msg->getSender()) { 
						(*iterate)->receiveMessage(msg); 
					}
				}
			}
			// otherwise, send the message to all recipients it's directed towards
			else { 
				std::vector<MessageBusNode*> recipients = (msg->getRecipients());

				for (auto reciever: recipients) {
					(reciever)->receiveMessage(msg);
				}
			}

		}
	}

