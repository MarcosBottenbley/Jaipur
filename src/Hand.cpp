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
    for (x = 0; x < get_hand_size (); x++)
    {
        delete hand[x];
    }

    hand.clear ();

    while (!is_herd_empty ())
    {
        delete herd.top ();
        herd.pop ();
    }
}

bool Hand::add_card (Card *c)
{
    if (c->get_type () == "Camel")
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

unsigned int Hand::get_hand_size () const
{
    return hand.size ();
}

Card* Hand::card_at (int index)
{
    Card* temp = 0;
    if (index < 0 || index >= (int) get_hand_size ())
    {
        return temp;
    }
    return hand[index];
}

Card* Hand::remove_card (int index)
{
    Card * temp = 0;
    if (!is_empty ())
    {
        temp = hand[index];
        hand.erase (hand.begin () + index);
    }
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Hand& aHand)
{
    unsigned int x;
    os << "Hand:  ";
    if  (aHand.is_empty ())
    {
        os << " No Goods Cards";
    }
    for (x = 0; x < aHand.hand.size (); x++)
    {
        os << " " << x+1 << ". [" << aHand.hand[x]->get_type () << "]";
    }
    if (aHand.get_herd_size () == 1)
    {
        os << ", " << aHand.get_herd_size () << " camel in herd." << std::endl;
    }
    else
    {
        os << ", " << aHand.get_herd_size () << " camels in herd." << std::endl;
    }
    return os;
}

bool Hand::is_empty () const
{
    return hand.empty ();
}

bool Hand::is_herd_empty () const
{
    return herd.empty ();
}

Card* Hand::get_camel ()
{
    Card *temp = 0;
    if (!is_herd_empty ())
    {
        temp = herd.top ();
        herd.pop ();
    }
    return temp;
}

unsigned int Hand::get_herd_size () const
{
    return herd.size ();
}
