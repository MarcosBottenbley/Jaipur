#ifndef MARKET_H
#define MARKET_H

#include "Card.h"

class Game;

class Market {

private:
	Card* mktCards[5];
	Game* parent;

public:
	Market();
	Market(Game*);
	Card* getCard(int index);
	Card* takeCard(int index);
	Card* swapCard(int index, Card* card);
	void addCard(int index, Card* card);
};

#endif

