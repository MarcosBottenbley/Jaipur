/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include "Card.h"
#include "Deck.h"

class Market
{
private:
    Card* mktCards[5];
    Deck &deck;
public:
    Market(Deck&);
    ~Market();
    Card* get_card(int index);//checks card at index
    Card* take_card(int index);//automatically replaces card
    Card* swap_card(int index, Card* card);//for trades
    //TODO: replace with operator overload
    void print_market();
};
