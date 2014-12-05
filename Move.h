#ifndef MOVE_H
#define MOVE_H
#include "Card.h"
#include "Player.h"
#include "Move.h"


class Move
{
	protected:
		Card *market;
		Player *player;
	public:
		Move();
		Move(Card *, Player *);
		virtual ~Move();
		virtual void makeMove() = 0;
};
#endif
	
