#ifndef TAKE_H
#define TAKE_H

#include "Move.h"

class Take : public Move
{
	private:
		//vector<Card*> mCards;
		int index;		//index of card to take, -1 if camels requested
	public:
		Take(Market &, Hand &, int);
		virtual ~Take();
		int makeMove();
};
#endif
