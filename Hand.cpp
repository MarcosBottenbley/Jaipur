#include "Hand.h"
#include <iostream>

Hand::Hand()
{}

Hand:: ~Hand()
{
	unsigned int x;
	for(x = 0; x < handSize(); x++)
		delete hand[x];

	hand.clear();

	while(!isHerdEmpty()) {
		delete herd.top();
		herd.pop();
	}
}

bool Hand::addCard(Card *c)
{
	if(c->getType() == "Camel") {
		herd.push(c);
		return true;
	}
	else if(hand.size() == MAX_SIZE) {
		delete c;
		return false;
	}
	else {
		hand.push_back(c);
		return true;
	}
}

unsigned int Hand::handSize()
{
	return hand.size();
}

Card* Hand::removeCard(int index)
{
	Card * temp = 0;
	if(!isEmpty()) {
		temp = hand[index];
		hand.erase(hand.begin()+index);
	}
	return temp;
}

void Hand::printHand() 
{
	unsigned int x;
	for(x = 0; x < hand.size(); x++)
		std::cout << hand[x]->getType() << std::endl;
	if(herdSize() == 1)
		std::cout << herdSize() << " camel in herd." << std::endl;
	else
		std::cout << herdSize() << " camels in herd." << std::endl;
}

bool Hand::isEmpty()
{
	return hand.empty();
}

bool Hand::isHerdEmpty()
{
	return herd.empty();
}

Card* Hand::getCamel()
{
	Card *temp = 0;
	if(!isHerdEmpty()) {
		temp = herd.top();
		herd.pop();
	}
	return temp;
}

unsigned int Hand::herdSize()
{
	return herd.size();
}
