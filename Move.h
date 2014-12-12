#ifndef MOVE_H
#define MOVE_H

#include "Card.h"
#include "Hand.h"
#include "Market.h"
#include <exception>
#include <vector>
#include "InvalidMoveEx.h"	//TODO: do we need to change this back?

using std::vector;

class Move
{
	protected:
		Market &market;
		Hand &hand;
		vector<int> getIndexes(bool *, int);
	public:
		Move(Market &,Hand &);
		virtual ~Move();
		virtual int makeMove() = 0;
};
#endif
	
