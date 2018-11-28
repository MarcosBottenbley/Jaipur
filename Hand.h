/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>
#include <stack>
#define MAX_SIZE 7

class Hand
{
    private:
        std::vector<Card *> hand;
        std::stack<Card *> herd;
    public:
        Hand();
        ~Hand();
        void clear();
        bool addCard(Card *);
        unsigned int handSize();
        Card* cardAt(int);  //card at given index
        Card* removeCard(int);
        void printHand();
        bool isEmpty();
        bool isHerdEmpty();
        Card* getCamel();
        unsigned int herdSize();
};
#endif
