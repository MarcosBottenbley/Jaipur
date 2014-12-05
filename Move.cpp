#include "Move.h"

Move::Move() : market(0), player(0)
{}

Move::Move(Card *c, Player *p)
{
	market = c;
	player = p;
}

Move::~Move()
{}
