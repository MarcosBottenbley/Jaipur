#include "Take.h"

Take::Take(Market &m, Hand &h, std::vector<Card*> c):
 Move(m,h), mCards(c)
{}
int Take::makeMove()
{
	for(unsigned int x = 0; x < mCards.size(); x++) {
		if(!hand.addCard(mCards[x]))
			throw InvalidMoveException;
	}

	return 0;
}
