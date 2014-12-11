#include "Trade.h"

Trade::Trade(Market &m, Hand &h, vector<Card*> pc, vector<Card*> mc):
 Move(m,h), pCards(pc), mCards(mc)
{}

int Trade::makeMove()
{
	int size = mCards.size();
	int size2 = pCards.size();

	if(size != size2)
		throw InvalidMoveException;
	else if(size > 5)
		throw InvalidMoveException;

	for(int x = 0; x < size; x++) {
		market.add(pCards[x]);
		hand.addCard(mCards[x]);
	}

	return 0;
}
