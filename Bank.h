/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

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
		void addTokens(int *,int,Type);
	public:
		Bank();
		Bank(int);
		~Bank();
		std::stack<Token*> getTokens(Type::Enum,int);
		void printBank();
		bool gameOver();
};
#endif

