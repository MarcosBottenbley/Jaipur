#include <iostream>
#include "Human.h"

Human::Human() {
	handSize = 0;
	wins = 0;
	camels = 0;
}

Human::Human(std::string hname) {
    name = hname;
    score = 0;
    wins = 0;
    camels = 0;
}

Human::~Human()
{}

Move* Human::getMove() {
	return NULL;
}

