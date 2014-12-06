#ifndef CARD_H
#define CARD_H

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
