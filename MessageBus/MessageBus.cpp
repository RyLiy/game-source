#include "Message.h"
#include "MessageBus.h"
#include "MessageBusNode.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iostream>
	/* To-do:
	- Reduce redundency between nodes and nodeClass; as node contains all of the data that nodeClass already contains. Probably eliminate the nodes vector, and use the map as a singular data source.
	- Create the ability to classify nodes into more than one system space, without redundency.
	- Create a persistant map, without writing to an external file. I.e., "that can be considered at the same time a store and a cache, using a design where data is always modified and read from the main computer memory, but also stored on disk in a format that is unsuitable for random access of data, but only to reconstruct the data back in memory once the system restarts." Use redis for this.
	- Create a better way to modify the map. I.e., add or remove nodes on the bus.
	- Once all is done, probably refactor the map name (currently: nodeClass) into the name systemMap or engineMap. From thereafter, the map will play a central role for the message bus; every component (read: class or object) in the entire engine should be able to be referenced from it.*/

	void MessageBus::addNode(MessageBusNode *node) {
		nodes.push_back(node);
		syncBusNode(std::vector<MessageBusNode*>{node});
	}

	void MessageBus::addNode(std::vector<MessageBusNode*> nodeList) {
		this->nodes.insert(nodes.end(), nodeList.begin(), nodeList.end());
		syncBusNode(nodeList);
	}

	void MessageBus::syncBusNode(std::vector<MessageBusNode*> nodeList) { //Set this bus instance as the bus for all of the nodes added
		for (auto node : nodeList) {
			node->setBus(this);
		}
	}

	void MessageBus::sendMessage(Message *msg) {
		messageQueue.push_back(msg);
		notify();
	}

	void MessageBus::notify() {
		for (auto message: messageQueue) { //iterates through message queue
			Message *msg = messageQueue.back(); 
			
			messageQueue.pop_back();


			if ((msg->getRecipients().empty())) { //if the message isn't directed towards a particular system space or component
				for (auto iterate = nodes.begin(); iterate != nodes.end(); iterate++) { //send the message to all nodes in the bus. I.e., all system spaces -- 'the global space'.
					if ((*iterate) != msg->getSender()) { (*iterate)->receiveMessage(msg); }
				}
			}
			else { //send the message to all nodes it's directed towards
				std::vector<MessageBusNode*> recipients = (msg->getRecipients());

				for (auto reciever: recipients) {
					(reciever)->receiveMessage(msg);
				}
			}

		}
	}

