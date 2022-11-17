#ifndef NODE_
#define NODE_

class Node
{
private:
	int item;
	Node* next;
	
public:
	Node(const int anItem);
	void setItem(const int anItem);
	void setNext(Node* nextNodePtr);
	int getItem() const;
	Node* getNext() const;
};

#endif
