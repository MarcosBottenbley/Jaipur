/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Market.h"
#include "Deck.h"
#include <iostream>

Market::Market(Deck &d):
 deck(d)
{
    for(int i = 0; i < 3; i++)
    {
        mktCards[i] = new Card("Camel");
    }

    mktCards[3] = d.getCard();
    mktCards[4] = d.getCard();
}

Market::~Market()
{
    for (int i = 0; i < 5; i++)
    {
        delete mktCards[i];
    }
}

Card* Market::getCard(int index) {
        return mktCards[index];
}

Card* Market::takeCard(int index) {
        Card* tempCard = mktCards[index];
        mktCards[index] = deck.getCard();
        return tempCard;
}

Card* Market::swapCard(int index, Card* card) {
        Card* tempCard = mktCards[index];
        mktCards[index] = card;
        return tempCard;
}

void Market::printMarket() {
    std::cout << "Market: ";
    for (int i = 0; i < 5; i++) {
                std::cout << i+1 << ". [" << mktCards[i]->getType() << "] ";
        //std::cout << i+1 << ". [" << Type.toString(mktCards[i]->getType()) << "] ";
    }
    std::cout << std::endl;
}

