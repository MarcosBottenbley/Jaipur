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
#include "State.h"

class CommandLineView;
class CommandLineController;

class Game : public State
{
friend class Move;

//public functions
public:
    //constructs game with RNG seeded to time
    Game (Player*, Player*);

    //takes a seed for the RNG
    Game (Player*, Player*, int rndSeed);

    ~Game ();

    //resets or inits the deck, market, and token piles, and
    //deals a hand of 5 cards to each player
    void init(CommandLineView* v, CommandLineController* c);
    void start();
    void update(float dt);
    void draw();

    void play_game ();

    bool execute_player_turn(Player* player);
    void print_board ();
    void print_players ();

    void end_round ();                //tallies player scores and awards a win to the
    bool end_game ();                 //determines if the game has been won

//private variables
private:
    //both player objects initialized with the init_player function
    Player* player1;
    Player* player2;

    //Object that represents the 5 cards that players can take or exchange
    Market* market;

    //vector of 9 token arrays representing the
    //6 types of goods tokens and 3 types of bonus tokens
    Bank* bank;

    //Object with a stack for the deck of cards
    Deck* deck;

    CommandLineView* view;
    CommandLineController* controller;

//private functions
private:
    void stop();
    int execute_move(Move*);

    //checks the deck and the bank objects to see if the game is over
    void determine_camel_winner();
    void reset_game();
    bool check_gameover();
    void pause();
};
