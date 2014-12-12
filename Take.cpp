#include "Take.h"

Take:: Take(Market & m, Hand & h, int i) :
	Move(m,h), index(i)
{}

Take::~Take()
{}

int Take::makeMove()
{
	if (market.getCard(index)->isCamel()) {	//if taking camels...
		for (int x = 0; x < 5; x++) {
			if (market.getCard(x)->isCamel()) {		//if card is a camel,
				hand.addCard(market.takeCard(x));	//take camel from market
			}
		}
		return 0;
	}

	//for(unsigned int x = 0; x < mCards.size(); x++) {
	//if(!hand.addCard(market.takeCard(x)))
	//	throw InvalidMoveException;
	//}

	hand.addCard(market.takeCard(index));	//Error checking for this in Player.getMove()

	return 0;
}
