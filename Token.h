/*	The Token class is used to represent each kind of token 
	(bonus, camel, etc.)
*/

class Token
{
private:
	string type;					//type of token (9 types in total, the 6 goods
									//and the 3 bonus types)
	int value;						//how many rupees the token will yield at the
									//end of the round
public:
	string getType();				//returns type
	int getValue();					//returns the rupee value of the token
	Token(string, int);				//constructor for Token
}