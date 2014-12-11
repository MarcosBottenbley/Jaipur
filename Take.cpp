#include "Take.h"

Take::Take(Market &m, Hand &h, int i):
 Move(m,h), index(i)
{}
int Take::makeMove()
{
	int camelsTaken = 0;
	if (market.getCard(index)->isCamel()) {	//if taking camels...
		for (int x = 0; x < 5; x++) {
			if (market.getCard()->isCamel()) {		//if card is a camel,
				hand.addCard(market.takeCard(x));	//take camel from market
				camelsTaken++;
			}
		}
		if (camelsTaken == 0)	//if no camels in market...
			throw InvalidMoveException;	
	}

	//for(unsigned int x = 0; x < mCards.size(); x++) {
	//if(!hand.addCard(market.takeCard(x)))	//TODO: hand.addCard() doesn't currently return bool
	//	throw InvalidMoveException;
	//}

	hand.addCard(market.takeCard(x));	//Error checking for this in Player.getMove()

	return 0;
}
