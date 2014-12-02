#ifndef TRADE_H
#define TRADE_H

#include "Move.h"
#include "Player.h"
#include "Card.h"
#include <vector>

class Trade : public Move
{
	private:
		std::vector<Card> marketCards;
		std::vector<Card> playerCards;
	public:
		Trade();
		Trade(Card * c, Player *p)
		: Move(c,p)
		{};

		virtual ~Trade();
		void makeMove();
};
#endif
