/*	The Card class encapsulates both goods cards and camels, using the 
	int value isCamel. 
*/

#include <string>

class Card
{
private:
	string type;					//type of goods card (gold, silver, etc.)

public:
	Card(std::string);				//constructor for Card

	std::string getType();			//returns type
	bool isCamel();					//returns true if camel, false otherwise
}
