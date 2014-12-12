#ifndef SELL_H
#define SELL_H

#include "Move.h"
#include "Bank.h"

class Sell : public Move
{
	private:
		vector<Card*> pCards;
		Bank &bank;
	public:
		Sell();
		Sell(Market &, Hand &, Bank &, vector<Card*>);
		virtual ~Sell();
		int makeMove();
};
#endif
