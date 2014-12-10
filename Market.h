#ifndef MARKET_H
#define MARKET_H

#include "Card.h"

class Market {
	Card* mktCards[5];

public:
	Card* getCard(int index);
	Card* takeCard(int index);
	Card* swapCard(int index, Card* card);
	void addCard(int index, Card* card);
};

#endif

