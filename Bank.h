#ifndef BANK_H
#define BANK_H

#include "Token.h"
#include "Type.h"
#include <stack>
#include <cstdlib>
#include <ctime>

class Bank
{
	private:
		std::stack<Token*> bank[9];
		void initBank();
		void shuffle(int *,int);
		void addTokens(int *,int,Type::Enum,std::string);
	public:
		Bank();
		Bank(int);
		std::stack<Token*> getTokens(Type::Enum,int);
		void printBank();
};
#endif

