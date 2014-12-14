#include "Take.h"

Take:: Take(Market & m, Hand & h, unsigned int i) :
	Move(m,h), index(i)
{}

Take::~Take()
{}

int Take::makeMove()
{
	InvalidMoveEx ime1("ERROR: invalid selection");
	InvalidMoveEx ime2("ERROR: hand is full. The hand is limited to 7 cards");
	if(index > 4)
		throw ime1;
	if(hand.handSize() == 7)
		throw ime2;

	if (market.getCard(index)->isCamel()) {	//if taking camels...
		for (int x = 0; x < 5; x++) { //finds camels
			if (market.getCard(x)->isCamel()) {
				hand.addCard(market.takeCard(x));	//take camel from market
			}
		}
		return 0;
	}

	hand.addCard(market.takeCard(index));

	return 0;
}
