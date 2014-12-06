#ifndef SELL_H
#define SELL_H

#include "Move.h"
#include "Player.h"
#include "Card.h"
#include <vector>

class Sell : public Move
{
	private:
		std::vector<Card> playerCards;
	public:
		Sell();
		Sell(Game *c, Player *p)
		: Move(c,p)
		{};
		virtual ~Sell();
		void makeMove(std::vector<int>, std::vector<int>, int);
};
#endif
