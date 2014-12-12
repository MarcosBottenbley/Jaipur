#include "Trade.h"

Trade::Trade(Market &m, Hand &h, std::vector<Card*> pc, std::vector<int> mc):
 Move(m,h), pCards(pc), mCards(mc)
{}

int Trade::makeMove()
{
	int size = mCards.size();
	int size2 = pCards.size();
	Card* temp = 0;

	if(size != size2)
		throw InvalidMoveException;
	else if(size > 5)
		throw InvalidMoveException;

	for(int x = 0; x < size; x++) {
		temp = market.swapCard(mc[x], pc[x]);
		hand.addCard(temp);
	}

	return 0;
}
