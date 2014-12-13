CC = g++
CCFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g
GCOV = -fprofile-arcs -ftest-coverage

all: JaipurMain

JaipurMain: JaipurMain.cpp Game.cpp Human.cpp Player.cpp AI.cpp Hand.cpp Market.cpp Card.cpp Take.cpp Trade.cpp Sell.cpp Move.cpp Token.cpp Deck.cpp Type.cpp Bank.cpp
		$(CC) $(CCFLAGS) JaipurMain.cpp Game.cpp Human.cpp Player.cpp AI.cpp Hand.cpp Market.cpp Card.cpp Take.cpp Trade.cpp Sell.cpp Move.cpp Token.cpp Deck.cpp Type.cpp Bank.cpp -o JaipurMain

Test:	Token.cpp Card.cpp Hand.cpp Type.cpp Bank.cpp Test.cpp
		$(CC) $(CCFLAGS) Token.cpp Card.cpp Hand.cpp Type.cpp Bank.cpp Test.cpp -o Test

Test2:	Token.cpp Card.cpp Hand.cpp Type.cpp Bank.cpp Deck.cpp Market.cpp Move.cpp Take.cpp Sell.cpp Trade.cpp Test2.cpp
		$(CC) $(CCFLAGS) Token.cpp Card.cpp Hand.cpp Type.cpp Bank.cpp Deck.cpp Market.cpp Move.cpp Take.cpp Sell.cpp Trade.cpp Test2.cpp -o Test2

Test3:	Game.cpp Player.cpp Market.cpp Deck.cpp Bank.cpp Human.cpp Card.cpp Token.cpp Hand.cpp Type.cpp Move.cpp Take.cpp Trade.cpp Sell.cpp Test3.cpp
		$(CC) $(CCFLAGS) Game.cpp Player.cpp Market.cpp Deck.cpp Bank.cpp Human.cpp Card.cpp Token.cpp Hand.cpp Type.cpp Move.cpp Take.cpp Trade.cpp Sell.cpp Test3.cpp -o Test3

PlayerTest: HumanTest.cpp Human.cpp Player.cpp Hand.cpp Market.cpp Card.cpp Take.cpp Trade.cpp Sell.cpp Move.cpp Token.cpp Deck.cpp Type.cpp Bank.cpp
		$(CC) $(CCFLAGS) HumanTest.cpp Human.cpp Player.cpp Hand.cpp Market.cpp Card.cpp Take.cpp Trade.cpp Sell.cpp Move.cpp Token.cpp Deck.cpp Type.cpp Bank.cpp -o PlayerTest

clean:
		rm JaipurMain Test Test2 Test3 PlayerTest
