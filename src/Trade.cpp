/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Trade.h"

Trade::Trade (Market &m, Hand &h, bool *pc, bool *mc, int c) : Move (m,h), camels (c)
{
    pIndexes = getIndexes (pc, 7);
    mIndexes = getIndexes (mc, 5);
}

Trade::~Trade ()
{}

int Trade::makeMove ()
{
    InvalidMoveEx ime1 ("ERROR: Did not pick an equal amount of cards from the market and the hand\n");
    InvalidMoveEx ime2 ("ERROR: You must trade at least two cards\n");
    InvalidMoveEx ime3 ("ERROR: This trade would result in you having more than 7 cards in hand\n");

    int size = mIndexes.size ();
    int size2 = pIndexes.size ();

    //checks to see if amount of cards are equal
    if (size != size2 + camels)
    {
        throw ime1;
    }
    else if (size < 2) //checks to see that they didn't pick either too many or too little cards
    {
        throw ime2;
    }
    else if (hand.handSize () + camels > 7)
    {
        throw ime3;
    }

    Card *temp = 0;

    for (int x = size2-1; x >= 0; x--)
    {
        temp = hand.removeCard (pIndexes[x]);        //remove backmost hand card
        temp = market.swapCard (mIndexes[x+camels], temp);   //put in market and take out market card
        hand.addCard (temp);         //add market card to player's hand

    }

    for (int i = 0; i < camels; i++)
    {
        temp = hand.getCamel ();
        temp = market.swapCard (mIndexes[i], temp);
        hand.addCard (temp);
    }

    return 0;
}
