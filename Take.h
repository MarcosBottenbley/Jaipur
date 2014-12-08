#ifndef TAKE_H
#define TAKE_H

#include "Move.h"

class Take : public Move
{
	private:
		void takeCamels();
	public:
		Take();
		//Take(Game *game, Player *plyr) : Move(game,plyr) {};
		virtual ~Take();
		void makeMove(std::vector<int>, std::vector<int>, int);
};
#endif
