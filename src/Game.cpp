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

/* Constructor */
Game::Game()
{
    std::srand(std::time(0));
}

Game::Game(int rndSeed)
{
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
void Game::startGame()
{
    std::string str;
    int p1, p2;
    //-----------------------------------------------------------------------------
    std::cout << "Welcome to Jaipur!" << std::endl << "Player 1, Enter your name: ";
    //-----------------------------------------------------------------------------
    std::cin >> str;
    //-----------------------------------------------------------------------------
    std::cout << "Is Player 1 a Human(1) or AI(2)?: ";
    //-----------------------------------------------------------------------------
    std::cin >> p1;
    //-----------------------------------------------------------------------------
    switch(p1)
    {
        case 1: player1 = new Human(str);
            break;
        case 2: player1 = new AI(str);
            break;
    }

    std::cout << "Player 2, Enter your name: ";
    std::cin >> str;
    std::cout << "Is Player 2 a Human(1) or AI(2)?: ";
    std::cin >> p2;
    switch(p2)
    {
        case 1: player2 = new Human(str);
            break;
        case 2: player2 = new AI(str);
            break;
    }
}

bool Game::InitPlayer(std::string name, bool human, int num)
{
    if (num == 1)
    {
        if (human)
        {
            player1 = new Human(name);
            return true;
        }
        player1 = new AI(name);
        return true;
    }
    else if (num == 2)
    {
        if (human)
        {
            player2 = new Human(name);
            return true;
        }
        player2 = new AI(name);
        return true;
    }
    return false;
}

void Game::startRound()
{
    deck = new Deck();
    market = new Market(*deck);
    bank = new Bank();

    deck->deal(player1->hand, player2->hand);
}

void Game::playGame()
{
    Move* movePtr;
    int retVal;

    std::cout << "Starting new round!" << std::endl;

    while(1)
    {
        movePtr = player1->getMove(*market, *bank);
        retVal = executeMove(movePtr);
        pause();
        if (retVal == -1)   //if invalid move, player1 tries again
            continue;
        else
            player1->addPoints(retVal);
        if (checkGameOver())
            break;
        while (1)
        {
            movePtr = player2->getMove(*market, *bank);
            retVal = executeMove(movePtr);
            pause();
            if (retVal == -1)   //if invalid move, player2 tries again
                continue;
            else
                player2->addPoints(retVal);
            if (checkGameOver())
                return;
            break;
        }
    }
}

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
            bank->printBank();
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
                endGame();
            }
        }
    }
}


// returns -1 on error, points earned if successful
int Game::executeMove(Move* mp)
{
    int points;

    try {
        points = mp->makeMove();
    } catch (InvalidMoveEx e) {
        std::cerr << e.what() << std::endl;
        delete mp;
        return -1;
    }

    delete mp;
    return points;
}

bool Game::checkGameOver()
{
        if (deck->gameOver() || bank->gameOver())
                return true;
        return false;
}

void Game::printPlayers()
{
    player1->printStats();
    std::cout << std::endl;
    player2->printStats();
}

void Game::printBoard()
{
    std::cout << "Market:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "[" << (market->getCard(i))->getType() << "] ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Bank:" << std::endl;
    bank->printBank();
}

bool Game::endRound()
{     //returns true if a player reaches 2 wins, false otherwise
    //Determine Camel Winner
    if ((player1->hand).herdSize() > (player2->hand).herdSize())
        player1->score += 5;
    else if ((player2->hand).herdSize() > (player1->hand).herdSize())
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

void Game::endGame()
{
    delete player1;
    delete player2;
    exit(1);
}
