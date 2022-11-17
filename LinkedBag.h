#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "Node.h"
#include <iostream>

class LinkedBag    //An instance of a LinkedBag class will be a group of nodes
{
private:
	Node* headPtr; //Pointer to first node
	int itemCount; //Current count of bag items
	
	//Returns either a pointer to the node containing a given entry
	//or the null pointer if the entry is not in the bag
	Node* getPointerTo(const int target) const;
	
public:
	LinkedBag();   //This is a constructor function to create an instance of the class
	//virtual ~LinkedBag(); //This is a destructor to dstroy an instance of the class
	int getCurrentSize() const; //This will return the itemCount
	bool isEmpty() const; //This will check whether itemCount is less than 1 or not, and return the result
	bool add(const int newEntry); //This will add a new node to the instance
	bool remove(const int anEntry); //This will remove a node from the instance
	//void clear(); //This will clear the content of an item
	bool contains(const int anEntry) const; //This will check the existence of an item
	int getFrequencyOf(const int anEntry) const; //This will return the freq. of an item
	void printBag() const; //This will print the content of the instance
    void removeDublicates(const int anItem);//This will remove the dublicates of anItem
};

#endif
