/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include "Card.h"
#include <vector>
#include <stack>
#include <iostream>
#define MAX_SIZE 7

class Hand
{
public:
    Hand();
    ~Hand();

    void clear ();
    bool addCard (Card *);
    Card* cardAt (int);  //card at given index
    Card* removeCard (int);
    Card* getCamel ();

    //getters
    bool isEmpty () const;
    bool isHerdEmpty () const;
    unsigned int getHerdSize () const;
    unsigned int getHandSize () const;

    friend std::ostream& operator<<(std::ostream& os, const Hand& aHand);
private:
    std::vector<Card *> hand;
    std::stack<Card *> herd;
};
