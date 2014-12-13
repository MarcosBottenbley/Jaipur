#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using std::string;
using std::endl;
using std::cerr;

Player::Player() {
    name = "Player";
    score = 0;
    wins = 0;
}

Player::Player(string pname){
    name = pname;
    score = 0;
    wins = 0;
}

Player::~Player()
{}

void Player:: printStats()
{
    std::cout<< name << "'s stats: ";

    std::cout << "Hand size: " << hand.handSize();
    std::cout << ", Camels: " << hand.herdSize();
    std::cout << ", Score: " << getScore();
    std::cout << ", Wins: " << wins << std::endl;
    hand.printHand();
}

void Player:: clear()
{
    for(int i = hand.handSize(); i>0; i--)
    {
        delete hand.removeCard(i);
    }
    for(int k = hand.herdSize(); k>0; k--)
    {
        delete hand.getCamel();
    }
}

void Player:: addCard(Card* card)
{
    hand.addCard(card);
}

Hand* Player::getHand() {
	return &hand;
}

void Player:: addToken(Token* token)
{
    tokens.push_back(token);
    score+=token->getValue();
}

int Player:: getScore()
{
    return score;
}
