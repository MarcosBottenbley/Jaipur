/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include <stack>
#include "Card.h"
#include "Hand.h"

class Deck
{
public:
    Deck ();
    ~Deck ();

    void initDeck ();
    void deal (Hand &,Hand &);
    Card * getCard ();
    void printDeck ();
    bool gameOver ();
private:
    std::stack<Card*> cards;
    bool emptyFlag;
};
