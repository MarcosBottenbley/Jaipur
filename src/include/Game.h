/**
 * The Game class represents a game of Jaipur. This class contains
 * both players and all the elements present on the game field.
 *
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include <vector>
#include <stack>
#include <string>
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "Bank.h"
#include "Market.h"
#include "Deck.h"

class Game
{
friend class Move;

//public functions
public:
    //constructs game with RNG seeded to time
    Game ();

    //takes a seed for the RNG
    Game (int rndSeed);

    ~Game ();

    void startGame ();

    //resets or inits the deck, market, and token piles, and
    //deals a hand of 5 cards to each player
    void startRound ();

    void playGame ();
    void printBoard ();
    void printPlayers ();

    //initializes a human or AI player and gives it a name
    bool initPlayer (std::string name, bool human, int num);

    bool endRound ();                //tallies player scores and awards a win to the
    void endGame ();                 //deallocates all memory used by the current game

//private variables
private:

    //both player objects initialized with the initPlayer function
    Player* player1;
    Player* player2;

    //Object that represents the 5 cards that players can take or exchange
    Market* market;

    //vector of 9 token arrays representing the
    //6 types of goods tokens and 3 types of bonus tokens
    Bank* bank;

    //Object with a stack for the deck of cards
    Deck* deck;

//private functions
private:
    int executeMove(Move*);

    //checks the deck and the bank objects to see if the game is over
    bool checkGameOver();
    void pause();
};
