/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include <cstdlib>
#include <iostream> //just for printDeck
#include "Deck.h"
#include "Market.h"

Deck::Deck ()
{
    initDeck ();
    emptyFlag = false;
}

Deck::~Deck ()
{
    for (int i = cards.size (); i > 0; i--)
    {
        delete cards.top ();
        cards.pop ();
    }
}

void Deck::initDeck ()
{
    Card* tempDeck[52];
    int i;

    /* Create cards */
    for (i = 0; i < 6; i++)
    {
        tempDeck[i] = new Card ("Diamond");
        tempDeck[i+6] = new Card ("Gold");
        tempDeck[i+12] = new Card ("Silver");
    }
    for (i = 0; i < 8; i++)
    {
        tempDeck[i+18] = new Card ("Cloth");
        tempDeck[i+26] = new Card ("Spice");
        tempDeck[i+34] = new Card ("Camel");
    }
    for (i = 42; i < 52; i++)
    {
        tempDeck[i] = new Card ("Leather");
    }

    /* Shuffle cards */
    int cardsInDeck = 52;
    int currRand;

    for (i = 0; i < 52; i++)
    {
        currRand = std::rand () % cardsInDeck;           //pick random card from list
        cards.push (tempDeck[currRand]);                 //push that card onto deck
        tempDeck[currRand] = tempDeck[--cardsInDeck];   //remove the card from the list
    }
}

void Deck::deal (Hand &h1, Hand &h2)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        h1.add_card (getCard ());
        h2.add_card (getCard ());
    }
}

Card* Deck::getCard ()
{
    if (cards.empty ())
    {
        emptyFlag = true;
        return 0;
    }

    Card *temp = cards.top ();
    cards.pop ();
    return temp;
}

//temporary method for testing
void Deck::printDeck ()
{
    std::stack<Card*> tempStack;
    for (int i = cards.size (); i > 0; i--)
    {
        std::cout << (cards.top ())->getType () << std::endl;
        tempStack.push (cards.top ());
        cards.pop ();
    }
    for (int j = tempStack.size (); j > 0; j--)
    {
        cards.push (tempStack.top ());
        tempStack.pop ();
    }
    std::cout << std::endl << std::endl;
}

bool Deck::gameOver ()
{
    return emptyFlag;
}
