/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
	private:
		std::string type;
	public:
		Card(std::string);
	
		std::string getType();
		bool isCamel();
};
#endif
