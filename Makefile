CC = g++
CCFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g
GCOV = -fprofile-arcs -ftest-coverage

all: Test Test2

Test:	Token.cpp Card.cpp Hand.cpp Type.cpp Bank.cpp Test.cpp
		$(CC) $(CCFLAGS) Token.cpp Card.cpp Hand.cpp Type.cpp Bank.cpp Test.cpp -o Test

Test2:	Token.cpp Card.cpp Hand.cpp Type.cpp Bank.cpp Deck.cpp Market.cpp Move.cpp Take.cpp Sell.cpp Trade.cpp Test2.cpp
		$(CC) $(CCFLAGS) Token.cpp Card.cpp Hand.cpp Type.cpp Bank.cpp Deck.cpp Market.cpp Move.cpp Take.cpp Sell.cpp Trade.cpp Test2.cpp -o Test2

clean:
		rm Test Test2
