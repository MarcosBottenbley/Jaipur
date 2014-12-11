#ifndef TRADE_H
#define TRADE_H

#include "Move.h"

class Trade : public Move
{
	private:
		vector<Card*> pCards;
		vector<Card*> mCards;
	public:
		Trade(Market &, Hand &, vector<Card*>, vector<Card*>);
		virtual ~Trade();
		int makeMove();
};
#endif
