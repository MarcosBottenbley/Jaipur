#ifndef MOVE_H
#define MOVE_H

#include "Card.h"
#include "Hand.h"
#include "Market.h"
#include <exception>
#include <vector>
#include "InvalidMoveException"

using std::vector;

class Move
{
	protected:
		Market &market;
		Hand &hand;
	public:
		Move(Market &,Hand &);
		virtual ~Move();
		virtual int makeMove() = 0;
};
#endif
	
