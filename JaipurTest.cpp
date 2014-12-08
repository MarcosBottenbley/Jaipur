/* Main test driver for first build of our Jaipur program.
*/

#include "Game.h"
//#include "Player.h"
//#include "Move.h"

int main()
{
    Game newGame(600120);
    newGame.startGame();
    newGame.startRound();

    newGame.printDeck();
    newGame.printBoard();
    newGame.printPlayers();
    //check that the tokens are good somehow

    //Take m1(newGame.market, newGame.player1);
    //m1.makeMove();
    //(newGame->player1).printStats();

    //Take m2(newGame.market, newGame.player1);
    //m2.makeMove();
    //(newGame->player1).printStats();

    //Trade m3(newGame.market, newGame.player1);
    //m3.makeMove();
    //newGame.printBoard();

    //Sell m4(newGame.market, newGame.player1);
    //m4.makeMove();
    //(newGame->player1).printStats();

    //newGame.endRound();
    //(newGame->player1).printStats();
    //newGame.endGame();
}
