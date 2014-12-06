#ifndef TAKE_H
#define TAKE_H

#include "Move.h"

class Take : public Move
{
	private:
		void takeCamels();
	public:
		Take(Game *game, Player *plyr) : Move(game,plyr) {};
		virtual ~Take();
		void makeMove(vector<Card> &);
};
#endif
