#include <iostream>
#include "Type.h"
#include "Market.h"
#include "Game.h"

Market::Market(Game* g) {
    parent = g;
}

Card* Market::getCard(int index) {
        return mktCards[index];
}

Card* Market::takeCard(int index) {
        Card* tempCard = mktCards[index];
        mktCards[index] = (parent->deck).top();
        (parent->deck).pop();
        return tempCard;
}

Card* Market::swapCard(int index, Card* card) {
        Card* tempCard = mktCards[index];
        mktCards[index] = card;
        return tempCard;
}

void Market::addCard(int index, Card* card) {
        mktCards[index] = card;
}

void Market::printMarket() {
	for (int i = 0; i < 5; i++) {
		std::cout << i+1 << ". [" << Type.toString(mktCards[i]->getType()) << "] ";
	}
	std::cout << endl;
}

