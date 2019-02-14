/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Hand.h"
#include <iostream>

Hand::Hand ()
{}

Hand::~Hand ()
{
    clear ();
}

void Hand::clear ()
{
    unsigned int x;
    for (x = 0; x < getHandSize (); x++)
    {
        delete hand[x];
    }

    hand.clear ();

    while (!isHerdEmpty ())
    {
        delete herd.top ();
        herd.pop ();
    }
}

bool Hand::addCard (Card *c)
{
    if (c->getType () == "Camel")
    {
        herd.push (c);
        return true;
    }
    else if (hand.size () == MAX_SIZE)
    {
        delete c;
        return false;
    }
    else
    {
        hand.push_back (c);
        return true;
    }
}

unsigned int Hand::getHandSize () const
{
    return hand.size ();
}

Card* Hand::cardAt (int index)
{
    Card* temp = 0;
    if (index < 0 || index >= (int) getHandSize ())
    {
        return temp;
    }
    return hand[index];
}

Card* Hand::removeCard (int index)
{
    Card * temp = 0;
    if (!isEmpty ())
    {
        temp = hand[index];
        hand.erase (hand.begin () + index);
    }
    return temp;
}

//Move this to an overloaded operator
void Hand::printHand ()
{
    unsigned int x;
    std::cout << "Hand:  ";
    if  (isEmpty ())
    {
        std::cout << " No Goods Cards";
    }
    for (x = 0; x < hand.size (); x++)
    {
        std::cout << " " << x+1 << ". [" << hand[x]->getType () << "]";
    }
    if (getHerdSize () == 1)
    {
        std::cout << ", " << getHerdSize () << " camel in herd." << std::endl;
    }
    else
    {
        std::cout << ", " << getHerdSize () << " camels in herd." << std::endl;
    }
}

bool Hand::isEmpty ()
{
    return hand.empty ();
}

bool Hand::isHerdEmpty ()
{
    return herd.empty ();
}

Card* Hand::getCamel ()
{
    Card *temp = 0;
    if (!isHerdEmpty ())
    {
        temp = herd.top ();
        herd.pop ();
    }
    return temp;
}

unsigned int Hand::getHerdSize () const
{
    return herd.size ();
}
