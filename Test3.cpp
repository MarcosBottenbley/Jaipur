/* Program for testing the Player and Game classes.
*/

#include "Game.h"

int main()
{
    

    Game newGame(600120);
    newGame.startGame();
    newGame.startRound();
    newGame.printBoard();
    newGame.printPlayers();
    newGame.playGame();
}
