#include "Market.h"
//#include "Game.h"		//only for deck. If deck is a class, we won't need this.

Card* Market::getCard(int index) {
        return mktCards[index];
}

Card* Market::takeCard(int index) {
        Card* tempCard = mktCards[index];
//        mktCards[index] = deck.top();         we need an included deck class for this, we can't just access
//        deck.pop();                           the deck without a specific game instance
        return tempCard;
}

Card* Market::swapCard(int index, Card* card) {
        Card* tempCard = mktCards[index];
        mktCards[index] = card;
        return tempCard;
}

