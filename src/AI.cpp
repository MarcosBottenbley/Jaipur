/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "AI.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

AI::AI(std::string name) : Player(name) {}

Move* AI::getMove(Market& market, Bank& bank)
{   
    Move* movePtr;
    
    //printStats();
    //market.printMarket();
    cout << endl;

    //if hand is not full, take the first card in the market
    //(if the card is a camel, makeMove will take all camels)
    if(hand.handSize() != 7)
        movePtr =  take(market);
    else
    {
        movePtr = sellOne(market, bank);
        
        if (movePtr == 0)
            movePtr = sellTwo(market, bank);
    }
    return movePtr;
}
    
Move* AI::take(Market& market)
{
    if(market.getCard(0)->getType() == "Camel")
        cout << name << " takes the camels." << endl;
    else
        cout << name << " takes a " << market.getCard(0)->getType() << " card." << endl;
    return new Take(market, hand, 0);
}

//if hand is full, go through the hand and sell the first card
//you find that isn't a valuable card (gold, silver, diamond)
Move* AI::sellOne(Market& market, Bank& bank)
{
    unsigned int i;
    std::string type;
    bool playerCards[7] {0};
    
    for (i = 0; i < hand.handSize(); i++)
    {
        type = hand.cardAt(i)->getType();
        if (type != "Diamond" && type != "Gold" && type != "Silver")
        {
            playerCards[i] = !(playerCards[i]);
            cout << name << " sells a " << type << " card." << endl;
            return new Sell(market, hand, bank, playerCards);
        }
    }
    return 0;
}

//this code will only execute if the AI has a full hand of only valuables,
//it loops through every combination of two cards until it finds a valid one
//and sells them
Move* AI::sellTwo(Market& market, Bank& bank)
{
    unsigned int i,j;
    std::string type1, type2;
    bool playerCards[7] {0};
    
    for (i = 0; i < hand.handSize(); i++)
    {
        for (j = 0; j < hand.handSize(); j++)
        {
            if (i == j)
                continue;
                
            type1 = hand.cardAt(i)->getType();
            type2 = hand.cardAt(j)->getType();
            
            if(type1 == type2)
            {
                playerCards[i] = !(playerCards[i]);
                playerCards[j] = !(playerCards[j]);
                cout << name << " sells two " << type1 << " cards." << endl;
                return new Sell(market, hand, bank, playerCards);
            }
        }
    }
    return 0;
}
