/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

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
