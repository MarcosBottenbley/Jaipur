#ifndef pg7_AI_h
#define pg7_AI_h
#include "Player.h"
#include "Take.h"
#include "Trade.h"
#include "Sell.h"

class AI : public Player {

public:
	Move* getMove(Market &market, Bank &bank);

}

#endif
