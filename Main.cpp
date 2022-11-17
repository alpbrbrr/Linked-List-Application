#include "LinkedBag.h"
#include <iostream>

int main()
{
	LinkedBag* myBag = new LinkedBag(); 
	myBag->add(2);
	myBag->add(10);
	myBag->add(10);
	myBag->add(10);
	myBag->add(10);
	myBag->add(10);
	myBag->add(20);
	myBag->add(20);
	myBag->add(1);
	
	std::cout<<"The content of the bag:" <<std::endl;
	myBag->printBag();
	
	myBag->removeDublicates(10);
	
	std::cout<<"The content of the bag:" <<std::endl;
	myBag->printBag();
	
	
	
	
	
	
	return 0;
}
