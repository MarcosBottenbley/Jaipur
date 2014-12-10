#include "Market.h"
//#include "Game.h"		//only for deck. If deck is a class, we won't need this.

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