#ifndef DECK_H
#define DECK_H

#include <stack>
#include "Card.h"

class Game;

class Deck {

private:
    std::stack<Card*> cards;
    Game * parent;

public:
    Deck(Game * g);
    void initDeck();
    void deal();
    Card * getCard();
    void printDeck();
};

#endif
