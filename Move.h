#ifndef MOVE_H
#define MOVE_H

class Move
{
	protected:
		Card *market;
		Player *player;
	public:
		Move();
		Move(Card *, Player *);
		virtual ~Move();
		virtual void makeMove() = 0;
};
#endif
	
