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

    void init_deck ();
    void deal (Hand &,Hand &);
    Card * get_card ();
    void print_deck ();
    bool gameover ();
private:
    std::stack<Card*> cards;
    bool emptyFlag;
};
