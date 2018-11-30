/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Sell.h"

#include <string>
#include <stack>
#include <iostream>

Sell::Sell (Market &m, Hand &h, Bank &b, bool *p):
 Move (m,h),bank (b)
{
    pIndexes = getIndexes (p, 7);
}

Sell::~Sell ()
{}

int Sell::makeMove ()
{
    InvalidMoveEx ime1 ("ERROR: You must sell at least two of a precious metal\n");
    InvalidMoveEx ime2 ("ERROR: All cards you sell must be of the same type\n");
    //checks: if "precious metal" that there are at least 2 cards
    int size = pIndexes.size ();

    std::string initType = hand.cardAt (pIndexes[0])->getType ();
    if (initType == "Gold" || initType == "Silver" || initType == "Diamond")
    {
        if (size < 2)
            throw ime1;
    }

    //checks to see if all cards are of the same type
    std::string currType;
    for (int x = 1; x < size; x++)
    {
        currType = hand.cardAt (pIndexes[x])->getType ();
        if (currType != initType)
            throw ime2;
    }

    //now that everything is checked it gets the tokens
    Type t (initType);
    std::stack<Token*> tokens = bank.getTokens (t.getEnum (),size);
    int points = 0;
    while (!tokens.empty ())
    {
        points += tokens.top ()->getValue ();
        delete tokens.top ();
        tokens.pop ();
    }

    for (int i = size-1; i >= 0; i--)
    {
        delete hand.removeCard (pIndexes[i]);
    }

    return points;
}
