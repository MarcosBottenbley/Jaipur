/*	The Card class encapsulates both goods cards and camels, using the 
	int value isCamel. 
*/

class Card
{
private:
	string type;					//type of goods card (gold, silver, etc.)
									//"camel" if isCamel is true
	bool isCamel;					//true if card is a camel, false otherwise
		
public:
	string getType();				//returns type
	bool isCamel();					//returns true if camel, false otherwise
	Card(string, bool);				//constructor for Card
}