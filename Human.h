#ifndef HUMAN_H
#define HUMAN_H
#include "Move.h"
#include "Player.h"
#include <string>


class Human : public Player {
	void sortVector(std::vector<int>);
public:
	Human();
	Human(std::string name);
	virtual ~Human();
	Move* getMove(Market &market);
};

#endif
