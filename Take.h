#ifndef TAKE_H
#define TAKE_H

#include "Move.h"

class Take : public Move
{
	private:
		void takeCamels();
	public:
		Take(Card *mrkt, Player *plyr) : Move(mrkt,plyr) {};
		virtual ~Take();
		void makeMove(vector<Card> &);
};
#endif
