#include "LinkedBag.h"
#include "Node.h"

LinkedBag::LinkedBag()
{
	headPtr = nullptr;
	itemCount = 0;
	
}

//LinkedBag::~LinkedBag()
//{
//	
//}

bool LinkedBag::isEmpty() const
{
	return headPtr == nullptr;	
}

int LinkedBag::getCurrentSize() const
{
	return itemCount;
}

bool LinkedBag::add(const int newEntry)
{
	if(itemCount == 0)
	{
		headPtr = new Node(newEntry); //You should assign the new node to a pointer, which is headPtr in this case.	
	}
	else
	{
		Node* nodeToBeAdded = new Node(newEntry);
		
		if(newEntry < headPtr->getItem())
		{
			nodeToBeAdded->setNext(headPtr);
			headPtr = nodeToBeAdded;
		}
		else
		{
			Node* prev = nullptr;
			Node* cur = headPtr;
			
			while((cur != nullptr)&&(cur->getItem() < newEntry))
			{
				prev = cur;
				cur = cur->getNext(); 	
			}
			
			prev->setNext(nodeToBeAdded);
			nodeToBeAdded->setNext(cur);
			
		}
	}
		
	itemCount++;
	return true;	
}

bool LinkedBag::remove(const int anEntry)
{
	Node* nodeToBeRemoved = getPointerTo(anEntry);
	bool canRemoveItem = (nodeToBeRemoved != nullptr);
	if(canRemoveItem)
	{
		if(nodeToBeRemoved == headPtr)
		{
			headPtr = nodeToBeRemoved->getNext();
		}
		else
		{
			Node* prev;
			for(prev = headPtr; prev->getNext() != nodeToBeRemoved; prev = prev->getNext());
			prev->setNext(nodeToBeRemoved->getNext());			
		}
		
		nodeToBeRemoved->setNext(nullptr);
		delete nodeToBeRemoved;
		nodeToBeRemoved = nullptr; 
		itemCount--;
	}
	return canRemoveItem;
}

//void LinkedBag::clear()
//{
//	
//}

void LinkedBag::printBag() const
{
	for(Node* cur = headPtr; cur != nullptr; cur = cur->getNext())
	{
		std::cout << cur ->getItem() <<std::endl;
	}	
}

int LinkedBag::getFrequencyOf(const int anEntry) const
{
	int frequency = 0;
	
	for(Node* cur = headPtr; cur !=nullptr; cur = cur->getNext())
	{
		if(cur->getItem()==anEntry)
		{
			frequency++;
		}
	}
	
	return frequency;	
}

Node* LinkedBag::getPointerTo(const int target) const
{
	for(Node* cur = headPtr ; cur !=nullptr; cur = cur->getNext())
	{
		if(cur->getItem()==target)
		{
			return cur;
		}
	}
	
	return nullptr;
	
}

bool LinkedBag::contains(const int anEntry) const
{
	return getPointerTo(anEntry) != nullptr;	
}

void LinkedBag::removeDublicates(const int anItem)
{
	if(itemCount<=1)
	{
		return;
	}
	
	
	Node* cur = headPtr->getNext();
	Node* prev = headPtr;
	Node* nodeToBeDeleted = nullptr;
	while(cur != nullptr)
	{
		if((prev->getItem() != cur->getItem()) || (cur->getItem() != anItem))
		{
			prev = cur;
			cur = cur->getNext();				
		}
		else
		{
			nodeToBeDeleted = cur;
			cur = cur->getNext();
			nodeToBeDeleted->setNext(nullptr);
			delete nodeToBeDeleted;
			nodeToBeDeleted = nullptr;
			prev ->setNext(cur);
			itemCount--;
			/*prev->setNext(cur->getNext());
			cur->setNext(nullptr);
			delete cur;
			cur = prev->getNext();
			itemCount--;*/			
		}
	}
	
	
	return;
}

