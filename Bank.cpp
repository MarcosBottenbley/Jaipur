#include "Bank.h"
#include <iostream>

using std::stack;
using std::string;
using std::srand;
using std::time;
using std::cout;
using std::cin;
using std::endl;

Bank::Bank()
{
	//srand(time(0));
	initBank();
}

Bank::Bank(int seed)
{
	srand(seed);
	initBank();
}

Bank::~Bank()
{
	for(int x = 0; x < 9; x++) {
		while(!bank[x].empty()) {
			delete bank[x].top();
			bank[x].pop();
		}
	}
}

void Bank::initBank()
{
	Type t;

	int arr1[5] = {7,7,5,5,5};
	addTokens(arr1,5,Type::DIAMOND,"Diamond");
	int arr2[5] = {6,6,5,5,5};
	addTokens(arr2,5,Type::GOLD,"Gold");
	int arr3[5] = {5,5,5,5,5};
	addTokens(arr3,5,Type::SILVER,"Silver");
	int arr4[7] = {5,3,3,2,2,1,1};
	addTokens(arr4,7,Type::CLOTH,"Cloth");
	addTokens(arr4,7,Type::SPICE,"Spice");
	int arr6[9] = {4,3,2,1,1,1,1,1,1};
	addTokens(arr6,9,Type::LEATHER,"Leather");

	int arr7[7] = {3,3,2,2,2,1,1};
	addTokens(arr7,7,Type::BONUS3,"Bonus3");
	int arr8[6] = {6,6,5,5,4,4};
	addTokens(arr8,6,Type::BONUS4,"Bonus4");
	int arr9[5] = {10,10,9,8,8};
	addTokens(arr9,5,Type::BONUS5,"Bonus5");
}

void Bank::addTokens(int *arr, int size, Type::Enum e, string t)
{
	if(e == Type::BONUS3 || e == Type::BONUS4 || e == Type::BONUS5)
		shuffle(arr,size);

	//string s_type = t.toString(e);
	for(int x = 0; x < size; x++) {
		bank[e].push(new Token(t,arr[x]));
	}
}

void Bank::shuffle(int *arr, int size)
{
	int index;
	int index2;
	int temp;
	for(int x = 0; x < 5000; x++) {
		index = rand()%size;
		index2 = rand()%size;
		temp = arr[index];
		arr[index] = arr[index2];
		arr[index2] = temp;
	}
}

stack<Token*> Bank::getTokens(Type::Enum t, int num)
{
	stack<Token*> tokens;

	for(int x = 0; x < num; x++) {
		tokens.push(bank[t].top());
		bank[t].pop();
	}

	if(num == 3) {
		tokens.push(bank[Type::BONUS3].top());
		bank[Type::BONUS3].pop();
	} else if(num == 4) {
		tokens.push(bank[Type::BONUS4].top());
		bank[Type::BONUS4].pop();
	} else if(num >= 5) {
		tokens.push(bank[Type::BONUS5].top());
		bank[Type::BONUS5].pop();
	}

	return tokens;
}

void Bank::printBank()
{
	for(int x = 0; x < 9; x++) {
		while(!bank[x].empty()) {
			std::cout << bank[x].top()->getType() << " ";
			std::cout << bank[x].top()->getValue() << std::endl;
			bank[x].pop();
		}
	}
}

bool Bank::gameOver() {
	int emptyStacks = 0;
	for (int i = 0; i < 6; i++) {
		if (bank[i].empty())
			emptyStacks++;
	}

	if (emptyStacks >= 3)
		return true;
	return false;
}

