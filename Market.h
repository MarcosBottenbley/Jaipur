#ifndef MARKET_H
#define MARKET_H

#include "Card.h"

class Game;

class Market {
	Card* mktCards[5];
	Game* parent;
public:
	Market();
	Market(Game*);
	Card* getCard(int index);
	Card* takeCard(int index);
	Card* swapCard(int index, Card* card);
	void addCard(int index, Card* card);
	void printMarket();
};

#endif

