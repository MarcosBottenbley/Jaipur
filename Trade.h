#ifndef TRADE_H
#define TRADE_H

#include "Move.h"

class Trade : public Move
{
	private:
		bool *pCards;
		bool *mCards;
		int camels;
	public:
		Trade(Market &, Hand &, bool *, bool *, int);
		virtual ~Trade();
		int makeMove();
};
#endif
