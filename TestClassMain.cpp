#include "TestClass.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	std::srand(1151994);

	cout << "Beginning Testing" << endl;
	TestClass test;

	test.testDeck();
	test.testMarket();
	test.testHand();
	test.testBank();
	test.testTake();
	test.testSell();
	test.testTrade();

	cout << "All tests completed successfully!" << endl;
	return 0;
}
