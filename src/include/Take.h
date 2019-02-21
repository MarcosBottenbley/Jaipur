/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#ifndef TAKE_H
#define TAKE_H

#include "Move.h"

class Take : public Move
{
    private:
        //vector<Card*> mCards;
        int index;      //index of card to take, -1 if camels requested
    public:
        Take(Market &, Hand &, unsigned int);
        virtual ~Take();
        int make_move();
};
#endif
