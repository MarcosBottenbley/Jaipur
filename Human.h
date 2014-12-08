#ifndef HUMAN_H
#define HUMAN_H
#include "Move.h"
#include "Player.h"
#include <string>


class Human : public Player {
public:
	Human();
	Human(std::string name);
	virtual ~Human();
	Move* getMove();
};

#endif
