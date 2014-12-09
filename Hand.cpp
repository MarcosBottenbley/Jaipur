#include "Hand.h"
#include <iostream>

Hand::Hand()
{}

bool Hand::addCard(Card *c)
{
	if(hand.size() == MAX_SIZE)
		return false;
	else {
		hand.push_back(c);
		return true;
	}
}

unsigned int Hand::handSize()
{
	return hand.size();
}

bool Hand::removeCard(int index)
{
	if(!isEmpty()) {
		hand.erase(hand.begin()+(index-1));
		return true;
	} else {
		return false;
	}
}

void Hand::printHand() 
{
	unsigned int x;
	for(x = 0; x < hand.size(); x++)
		std::cout << hand[x]->getType() << std::endl;
}

bool Hand::isEmpty()
{
	return hand.empty();
}
