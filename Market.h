#ifndef MARKET_H
#define MARKET_H

#include "Card.h"
#include "Deck.h"

class Market {

private:
	Card* mktCards[5];
	Deck &deck;

public:
	Market(Deck&);
	~Market();
	Card* getCard(int index);//checks card at index
	Card* takeCard(int index);//automatically replaces card
	Card* swapCard(int index, Card* card);//for trades
	void printMarket();
};

#endif

