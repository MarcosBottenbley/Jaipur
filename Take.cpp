#include "Take.h"

Take:: Take(Market & m, Hand & h, unsigned int i) :
	Move(m,h), index(i)
{}

Take::~Take()
{}

int Take::makeMove()
{
	InvalidMoveEx ime;
	if(index > 4)
		throw ime;

	if (market.getCard(index)->isCamel()) {	//if taking camels...
		for (int x = 0; x < 5; x++) { //finds camels
			if (market.getCard(x)->isCamel()) {
				hand.addCard(market.takeCard(x));	//take camel from market
			}
		}
		return 0;
	}

	if(!hand.addCard(market.takeCard(index))) {
		throw ime;
	}

	return 0;
}
