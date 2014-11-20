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
	void takeTurn();				//the player gets an option to take a card, exchange
									//cards, take camels, or sell
	void take();					//if the player's hand is not full, a selected
									//card from the market is added to the hand
									//and fillMarket is then called
	void exchange();				//the player selects a number of cards from his hand
									//or herd and exchanges them with the same number of
									//cards from the market
	void getCamels();				//all the camels from the market are aded to the player's
									//herd and fillMarket is called
	void sell();					//the player selects a number of goods cards (of the
									//same type) which are then discarded. the same number of
									//goods tokens of that type are awarded to the player,
									//and a bonus sale token if applicable
}