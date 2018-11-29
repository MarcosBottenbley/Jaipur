/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Hand.h"
#include <iostream>

Hand::Hand()
{}

Hand::~Hand()
{
    clear();
}

void Hand::clear()
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

Card* Hand::cardAt(int index) {
    Card* temp = 0;
    if (index < 0 || index >= (int)handSize()) {        //if index out of bounds...
        return temp;
    }
    return hand[index];
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
    std::cout << "Hand:  ";
    if (isEmpty())
        std::cout << " No Goods Cards";
    for(x = 0; x < hand.size(); x++)
        std::cout << " " << x+1 << ". [" << hand[x]->getType() << "]";
    if(herdSize() == 1)
        std::cout << ", " << herdSize() << " camel in herd." << std::endl;
    else
        std::cout << ", " << herdSize() << " camels in herd." << std::endl;
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
