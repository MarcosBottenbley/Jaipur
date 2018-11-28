/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Game.h"

int main() {
    Game game;
    game.startGame();       //get player names.

    for (int i = 0; i < 3; i++) {
        game.startRound();
        game.playGame();
        if (game.endRound())
            break;
    }
    game.endGame();
    return 0;
}

