#ifndef TRADE_H
#define TRADE_H

#include "Move.h"

class Trade : public Move
{
	private:
		std::vector<Card*> pCards;
		std::vector<Card*> mCards;
	public:
		Trade(Market &, Hand &, std::vector<Card*>, std::vector<int>);
		virtual ~Trade();
		int makeMove();
};
#endif
