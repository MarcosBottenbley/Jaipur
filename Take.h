#ifndef TAKE_H
#define TAKE_H

#include "Move.h"

class Take : public Move
{
	private:
		vector<Card*> mCards;
	public:
		Take(Market &, Hand &, vector<Card*>);
		virtual ~Take();
		int makeMove();
};
#endif
