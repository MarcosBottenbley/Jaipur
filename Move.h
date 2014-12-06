#ifndef MOVE_H
#define MOVE_H

#include "Card.h"
#include "Player.h"
#include <exception>
#include <vector>
#include "InvalidMoveException.h"

class Move
{
	protected:
		Game *game;
		Player *player;
	public:
		Move();
		Move(Game *, Player *);
		virtual ~Move();
		virtual void makeMove(std::vector<int>, std::vector<int>, int) = 0;
		//parameters in makeMove for testing purposes
};
#endif
	
