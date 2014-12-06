#ifndef MOVE_H
#define MOVE_H

#include "Card.h"
#include "Player.h"
#include <exception>
#include "InvalidMoveException"

class Move
{
	protected:
		Card *market;
		Player *player;
	public:
		Move();
		Move(Game *, Player *);
		virtual ~Move();
		virtual void makeMove(vector<Card*> &, vector<Card*> &, int) = 0;
		//parameters in makeMove for testing purposes
};
#endif
	
