#include "Sell.h"

#include <string>

//void Sell::makeMove(vector<int> mcards,vector<int> pcards,int)
//{
//	int size = pcards.size();
//	std::string initType = player.hand[pcards[0]]->getType();
//	if(initType == "Gold" || initType == "Silver" || initType == "Diamond"){
//		if(size < 2)
//			throw InvalidMoveException;
//	}
//	for(int x = 1; x < size-1; x++){
//		std::string currType = player.hand[pcards[x]]->getType();
//		if(currType != initType)
//			throw InvalidMoveException;
//	}
//	//may need a bank class
//	vector<Token*> tokens = game->getTokens();
//	for(int x = 0; x < tokens.size(); x++)
//		player.tokens.push_back(tokens[x]);
//}
