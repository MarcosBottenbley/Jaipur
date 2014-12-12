#ifndef TRADE_H
#define TRADE_H

#include "Move.h"

class Trade : public Move
{
	private:
		bool pCards[7];
		bool mCards[5];
		int nextTrue(bool[], int);
	public:
		Trade(Market &, Hand &, bool[], bool[]);
		virtual ~Trade();
		int makeMove();
};
#endif
