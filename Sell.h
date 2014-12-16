/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#ifndef SELL_H
#define SELL_H

#include "Move.h"
#include "Bank.h"
#include "Type.h"

class Sell : public Move
{
	private:
		std::vector<int> pIndexes;
		Bank &bank;
	public:
		Sell();
		Sell(Market &, Hand &, Bank &, bool *);
		virtual ~Sell();
		int makeMove();
};
#endif
