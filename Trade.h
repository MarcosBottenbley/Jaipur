#ifndef TRADE_H
#define TRADE_H

#include "Move.h"
#include "Card.h"
#include <vector>

class Trade : public Move
{
	public:
		Trade();
//		Trade(Game * c, Player *p)
//		: Move(c,p)
//		{};

		virtual ~Trade();
		void makeMove(std::vector<int>,std::vector<int>,int);
};
#endif
