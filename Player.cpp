//
//  Player.cpp
//  pg7
//
//  Created by Syed Hossain on 12/3/14.
//  Copyright (c) 2014 syed. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "Card.h"

using std::string;

using std::endl;
using std::cerr;

Player::Player(string pname){
    name = pname;
    score = 0;
    wins = 0;
    camels = 0;
    
}

void Player:: printStats()
{
    std::cout<< name << " 's stats: ";
    
    std::cout<< "hand size: " << handSize;
    std::cout<< "Wins: " << wins;
    std::cout<< "Camels: " << camels;
    std::cout<<  "hand: ";
    for(int i = 0; i<hand.size(); i++)
    {
        std::cout << hand[i]->getType();
        
    }
    
}

void Player:: clear()
{
    for(int i = hand.size(); i>0; i--)
    {
        delete hand.back();
        hand.pop_back();
    }
    for(int k = camelCards.size(); k>0; k--)
    {
        delete camelCards.top();
        camelCards.pop();
    }
}

void Player:: addCard(Card* card)
{
    if(card->isCamel())
    {
        camelCards.push(card);
        return;
    }
    
    hand.push_back(card);
    
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




