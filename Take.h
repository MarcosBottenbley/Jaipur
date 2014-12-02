#ifndef TAKE_H
#define TAKE_H

#include "Move.h"
#include "Player.h"
#include "Card.h"
#include <vector>

class Take : public Move
{
	private:
		void takeCamels();
		std::vector<Card> marketCards;
	public:
		Take(Card *mrkt, Player *plyr) : Move(mrkt,plyr) {};
		virtual ~Take();
		void makeMove();
};
#endif
