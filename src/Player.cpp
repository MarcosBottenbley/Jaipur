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

std::ostream& operator<<(std::ostream& os, const Player& aPlayer)
{
    os << aPlayer.name << "'s Stats\n";
    os << "Hand size: " << aPlayer.hand.getHandSize ();
    os << ", Camels: " << aPlayer.hand.getHerdSize ();
    os << ", Score: " << aPlayer.getScore ();
    os << ", Wins: " << aPlayer.wins << std::endl;
    os << aPlayer.hand;
    return os;
}

int Player::GetHandSize () const
{
    return hand.getHandSize();
}

int Player::GetHerdSize () const
{
    return hand.getHerdSize ();
}

int Player::GetNumWins () const
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

const Hand* Player::getHand () const
{
    return &hand;
}

void Player::addPoints (int points)
{
    score += points;
}

int Player::getScore () const
{
    return score;
}
