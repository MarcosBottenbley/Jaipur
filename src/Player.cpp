/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <string>

Player::Player ()
{
    name = "Player";
    score = 0;
    wins = 0;
}

Player::Player (std::string pname)
{
    name = pname;
    score = 0;
    wins = 0;
}

Player::~Player ()
{}

//TODO: remove
void Player::printStats ()
{
    std::cout<< name << "'s Stats" << std::endl;

    std::cout << "Hand size: " << hand.handSize ();
    std::cout << ", Camels: " << hand.herdSize ();
    std::cout << ", Score: " << getScore ();
    std::cout << ", Wins: " << wins << std::endl;
    hand.printHand ();
}

/*
std::ostream& operator<<(std::ostream& os, const Player& aPlayer)
{
    os << aPlayer.name << "'s Stats\n";
    os << "Hand size: " << aPlayer.hand.handSize ();
    os << ", Camels: " << aPlayer.hand.herdSize ();
    os << ", Score: " << aPlayer.getScore ();
    os << ", Wins: " << aPlayer.wins << std::endl;
    //hand.printHand ();
}
*/

int Player::GetHandSize ()
{
    return hand.handSize();
}

int Player::GetHerdSize ()
{
    return hand.herdSize ();
}

int Player::GetNumWins ()
{
    return wins;
}

void Player::clear ()
{
    hand.clear ();
    score = 0;
}

void Player::addCard (Card* card)
{
    hand.addCard (card);
}

Hand* Player::getHand ()
{
    return &hand;
}

void Player::addPoints (int points)
{
    score += points;
}

int Player::getScore ()
{
    return score;
}
