/*	The Player class is used to store all the data related to 
	one of the game's players. (# of wins, cards in hand, etc.)
*/

class Player
{
private:
	string name;					//the player's name
	Card[7] hand;					//goods cards held by player; max 7
	int handSize;					//how many goods cards are currently in
									//the player's hand
	vector<Token> tokens;			//tokens currently owned by player
	int wins;						//number of seals of excellence player has
	int camels;						//how many camel cards are currently in
									//the player's herd
public:
	virtual Move getMove() = 0;		//the player gets an option to take a card, exchange
}
