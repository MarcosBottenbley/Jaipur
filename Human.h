#ifndef HUMAN_H
#define HUMAN_H
#include "Move.h"
#include "Player.h"



class Human : public Player {
public:
	Human();
	Move getMove();
};

#endif
