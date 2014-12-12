#ifndef SELL_H
#define SELL_H

#include "Move.h"
#include "Bank.h"
#include "Type.h"

class Sell : public Move
{
	private:
		bool *pCards;
		Bank &bank;
	public:
		Sell();
		Sell(Market &, Hand &, Bank &, bool *);
		virtual ~Sell();
		int makeMove();
};
#endif
