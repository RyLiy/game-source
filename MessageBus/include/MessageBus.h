#pragma once
#include <vector>
#include <map>
#include <optional>
#include <iostream>
#include <algorithm>

// Forward declarations
class MessageBusNode;
class Message;

class MessageBus {
public:
    void addNodes(MessageBusNode* node);
    void addNodes(std::vector<MessageBusNode*> nodeList);
    void syncBusNode(std::vector<MessageBusNode*> nodeList);
    void sendMessage(Message* msg);
    void notify();

private:
    std::vector<MessageBusNode*> nodes;
    std::vector<Message*> messageQueue;
    std::map<std::vector<MessageBusNode>, std::string> engineMap;
};

class Message {
public:
    Message(std::string event, MessageBusNode* sender, MessageBusNode* component);
    Message(std::string event, MessageBusNode* sender, std::vector<MessageBusNode*> component);
    Message(std::string event, MessageBusNode* sender);
    std::string getMessage();
    MessageBusNode* getSender();
    std::vector<MessageBusNode*> getRecipients();

private:
    std::string event;
    MessageBusNode* sender;
    std::vector<MessageBusNode*> componentList;
};

class MessageBusNode {
public:
    //MessageBusNode(MessageBus* bus) : bus(bus) {} // Initialize bus in the constructor
    virtual void receiveMessage(Message* event);
    void sendMessage(std::string msg);
    void sendMessage(std::string msg, MessageBusNode* receiver);

    void sendMessage(std::string msg, std::vector<MessageBusNode*> receivers);
    void setBus(MessageBus* bus);

private:
    MessageBus* bus;
};