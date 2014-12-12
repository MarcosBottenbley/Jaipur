#ifndef DECK_H
#define DECK_H

#include <stack>
#include "Card.h"
#include "Hand.h"

class Deck {

private:
    std::stack<Card*> cards;
    bool emptyFlag;
public:
    Deck();
    ~Deck();
    void initDeck();
    void deal(Hand &,Hand &);
    Card * getCard();
    void printDeck();
    bool gameOver();
};

#endif
