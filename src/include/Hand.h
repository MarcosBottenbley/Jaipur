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
    bool add_card (Card *);
    Card* card_at (int);  //card at given index
    Card* remove_card (int);
    Card* get_camel ();

    //getters
    bool is_empty () const;
    bool is_herd_empty () const;
    unsigned int get_herd_size () const;
    unsigned int get_hand_size () const;

    friend std::ostream& operator<<(std::ostream& os, const Hand& aHand);
private:
    std::vector<Card *> hand;
    std::stack<Card *> herd;
};
