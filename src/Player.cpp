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
    os << "Hand size: " << aPlayer.hand.get_hand_size ();
    os << ", Camels: " << aPlayer.hand.get_herd_size ();
    os << ", Score: " << aPlayer.get_score ();
    os << ", Wins: " << aPlayer.wins << std::endl;
    os << aPlayer.hand;
    return os;
}

int Player::get_hand_size () const
{
    return hand.get_hand_size();
}

int Player::get_herd_size () const
{
    return hand.get_herd_size ();
}

int Player::get_num_wins () const
{
    return wins;
}

void Player::clear ()
{
    hand.clear ();
    score = 0;
}

void Player::add_card (Card* card)
{
    hand.add_card (card);
}

const Hand* Player::get_hand () const
{
    return &hand;
}

void Player::add_points (int points)
{
    score += points;
}

int Player::get_score () const
{
    return score;
}
