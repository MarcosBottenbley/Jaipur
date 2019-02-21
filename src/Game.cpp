/*
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Game.h"       //includes Card.h, Token.h, Player.h vector and stack
#include "Market.h"
#include "Deck.h"
#include <iostream>
#include <cstdlib>      //for random numbers only
#include <ctime>
#include <climits>

/* Both constructors initialize the
 * random number generator.
 * Which is used
 */
Game::Game()
{
    //seeds with time
    std::srand(std::time(0));
}

Game::Game(int rndSeed)
{
    //takes in a given seed
    //mostly used for debugging purposes.
    std::srand(rndSeed);
}

Game::~Game ()
{
    if (deck != NULL)
        delete deck;
    if (bank != NULL)
        delete bank;
    if (market != NULL)
        delete market;
    if (player1 != NULL)
        delete player1;
    if (player2 != NULL)
        delete player2;
}

//TODO: remove function
void Game::start_game ()
{
    std::string playerName;
    int playerClass;
    //-----------------------------------------------------------------------------
    std::cout << "Welcome to Jaipur!" << std::endl << "Player 1, Enter your name: ";
    //-----------------------------------------------------------------------------
    std::cin >> playerName;
    //-----------------------------------------------------------------------------
    std::cout << "Is Player 1 a Human(1) or AI(2)?: ";
    //-----------------------------------------------------------------------------
    std::cin >> playerClass;
    //-----------------------------------------------------------------------------
    init_player(playerName, (playerClass == 1), 1);

    std::cout << "Player 2, Enter your name: ";
    std::cin >> playerName;
    std::cout << "Is Player 2 a Human(1) or AI(2)?: ";
    std::cin >> playerClass;
    init_player(playerName, (playerClass == 1), 2);
}

/*
 * Initializes a player object.
 * Parameters:
 * -Name for the name of the player
 * -Boolean to check if the player is human or AI
 * -Int the indicates turn order
 */
bool Game::init_player(std::string name, bool human, int num)
{
    if (num != 1 && num != 2)
    {
        return false;
    }
    if (num == 1)
    {
        if (human)
        {
            player1 = new Human(name);
        }
        else
        {
            player1 = new AI(name);
        }
    }
    else if (num == 2)
    {
        if (human)
        {
            player2 = new Human(name);
        }
        else
        {
            player2 = new AI(name);
        }
    }
    return true;
}

/*
 * Initializes all of the objects that are
 * needed to play the game ie. deck, market, bank
 * and deals cards to the players
 */
void Game::start_round()
{
    deck = new Deck();
    market = new Market(*deck);
    bank = new Bank();

    deck->deal(player1->hand, player2->hand);
}

/*
 * Main game loop
 */
void Game::play_game()
{
    Move* movePtr;
    int retVal;

    std::cout << "Starting new round!" << std::endl;

    while(1)
    {
        //get player 1's move and perform it
        movePtr = player1->get_move(*market, *bank);
        retVal = execute_move(movePtr);
        pause();
        if (retVal == -1)   //if invalid move, player1 tries again
            continue;
        else
            player1->add_points(retVal);
        if (check_game_over())
            break;
        while (1)
        {
            //get player 2's move and perform it
            movePtr = player2->get_move(*market, *bank);
            retVal = execute_move(movePtr);
            pause();
            if (retVal == -1)   //if invalid move, player2 tries again
                continue;
            else
                player2->add_points(retVal);
            if (check_game_over())
                return;
            break;
        }
    }
}

/*
 * Pauses the CLI game to give player a chance
 * to quit or look at the board
 */
void Game::pause()
{
    char ch;
    while(1)
    {
        std::cout << std::endl << "Input C to continue, B to see the board or Q to quit the game: ";
        std::cin >> ch;

        if (tolower(ch) == 'c')
            break;
        if (tolower(ch) == 'b')
        {
            market->printMarket();
            bank->print_bank();
        }
        if (tolower(ch) == 'q')
        {
            std::cout << "Do you really want to quit? [Y/N]: ";
            std::cin >> ch;
            if (tolower(ch) == 'y')
            {
                delete bank;
                delete market;
                delete deck;
                end_game();
            }
        }
    }
}


// returns -1 on error, points earned if successful
int Game::execute_move(Move* mp)
{
    int points;

    try {
        points = mp->makeMove();
    } catch (InvalidMoveEx e) {
        std::cerr << e.what() << std::endl;
        points = -1;
    }

    delete mp;
    return points;
}

bool Game::check_game_over()
{
    return (deck->game_over() || bank->game_over());
}

void Game::print_players()
{
    std::cout << *player1 << std::endl;
    std::cout << *player2 << std:: endl;
}

void Game::print_board()
{
    std::cout << "Market:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "[" << (market->getCard(i))->getType() << "] ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Bank:" << std::endl;
    bank->print_bank();
}

bool Game::end_round()
{
    //returns true if a player reaches 2 wins, false otherwise
    //Determine Camel Winner
    if ((player1->hand).get_herd_size() > (player2->hand).get_herd_size())
        player1->score += 5;
    else if ((player2->hand).get_herd_size() > (player1->hand).get_herd_size())
        player2->score += 5;

    if (player1->score > player2->score) {
        player1->wins++;
        std::cout << player1->name << " wins the round!" << std::endl << std::endl;
    }
    else if (player2->score > player1->score) {
        player2->wins++;
        std::cout << player2->name << " wins the round!" << std::endl << std::endl;
    }
    /*else {        //if score tied...
        if (player1->tokens.size() > player2->tokens.size())
            player1->wins++;
        else if (player2->tokens.size() > player1->tokens.size())
            player2->wins++;
        else {
            //result in draw
        }
    }*/

    player1->clear();
    player2->clear();

    delete deck;
    delete market;
    delete bank;

    if (player1->wins == 2) {
        std::cout << player1->name << " wins the game!" << std::endl;
        return true;
    } else if (player2->wins == 2) {
        std::cout << player2->name << " wins the game!" << std::endl;
        return true;
    }
    return false;
}

void Game::end_game()
{
    delete player1;
    delete player2;
    exit(1);
}
