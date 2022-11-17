#include "Node.h" //This CPP file includes the functions to create an object with some features

Node::Node(const int anItem) //This is the constructor function
{
	item = anItem;
	next = nullptr;	
}

void Node::setItem(const int anItem)
{
	item = anItem; 
}

void Node::setNext(Node* nextNodePtr)
{
	next = nextNodePtr;
}

int Node::getItem() const
{
	return item;
}

Node* Node::getNext() const
{
	return next;
}
