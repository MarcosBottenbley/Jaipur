/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Market.h"
#include "Deck.h"
#include <iostream>

Market::Market(Deck &d) : deck(d)
{
    for(int i = 0; i < 3; i++)
    {
        mktCards[i] = new Card("Camel");
    }

    mktCards[3] = d.get_card();
    mktCards[4] = d.get_card();
}

Market::~Market()
{
    for (int i = 0; i < 5; i++)
    {
        delete mktCards[i];
    }
}

Card* Market::get_card(int index)
{
        return mktCards[index];
}

Card* Market::take_card(int index)
{
        Card* tempCard = mktCards[index];
        mktCards[index] = deck.get_card();
        return tempCard;
}

Card* Market::swap_card(int index, Card* card)
{
        Card* tempCard = mktCards[index];
        mktCards[index] = card;
        return tempCard;
}

void Market::print_market()
{
    //TODO: change to display market and connect with GUI
    std::cout << "Market: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << i+1 << ". [" << mktCards[i]->get_type() << "] ";
        //std::cout << i+1 << ". [" << Type.to_string(mktCards[i]->get_type()) << "] ";
    }
    std::cout << std::endl;
}
