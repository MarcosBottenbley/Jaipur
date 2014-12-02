/*  The Game class represents a game of Jaipur. This class contains
	both players and all the elements present on the game field.
*/
//Syedtesting
class Game
{
private:
	Player player1;
	Player player2;
	Card[5] market;					//the 5 cards that players can take or exchange
	vector<Token>[9] bank;			//vector of 9 token arrays representing the
									//6 types of goods tokens and 3 types of bonus tokens
	Card[40] deck;					//the pile of cards
	public:
	void startGame();				
	void startRound();				//resets the deck, market, and token piles, and
									//deals a hand of 5 cards to each player
	void initPlayers();				//creates the two Player objects for the game,
									//prompts for names and whether players are human/AI
	void makeDeck();				//initializes a randomized deck of 55 cards
	void fillMarket();				//deals cards from the deck to fill any empty
									//spaces in the market
	void endRound();				//tallies player scores and awards a win to the
									//player with the most rupees. If one player has
									//two wins, endGame() is called.
	void endGame();					//deallocates all memory used by the current game
}
