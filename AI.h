#ifndef pg7_AI_h
#define pg7_AI_h
#include "Player.h"
#include "Take.h"
#include "Trade.h"
#include "Sell.h"
#include <string>

class AI : public Player {

public:
	Move* getMove(Market &market, Bank &bank);
	AI(std::string name);
private:
	Move* take(Market& market);
	Move* sellOne(Market& market, Bank& bank);
	Move* sellTwo(Market& market, Bank& bank);
};

#endif
