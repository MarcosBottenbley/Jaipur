/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Game.h"
#include "Application.h"

int main(int argc, char *argv[])
{
    Game game;
    game.startGame();       //get player names.
    Application::init(800, 600);

    for (int i = 0; i < 3; i++)
    {
        game.startRound();
        game.playGame();
        if (game.endRound())
        {
            break;
        }
    }
    game.endGame();
    Application::quit();
    return 0;
}
