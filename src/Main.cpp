/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Game.h"
#include "Application.h"

int main(int argc, char *argv[])
{
    /*
    if (!Application::init(800, 600))
    {
        return EXIT_FAILURE;
    }
    */

    //Open menu for application
    //show menu with options for new game, continue or options
    //begin a new game or continue a game
    //create a game object and begin a game


    Game game;
    game.start_game();
    for (int i = 0; i < 3; i++)
    {
        game.start_round();
        game.play_game();
        if (game.end_round())
        {
            break;
        }
    }

    game.end_game();
    //Application::quit();
    return EXIT_SUCCESS;
}
