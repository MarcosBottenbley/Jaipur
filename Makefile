CC = g++
CFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g

default: JaipurTest

JaipurTest: JaipurTest.o Game.o
	$(CC) $(CFLAGS) -o JaipurTest JaipurTest.o Game.o
	
Game.o: Game.cpp Token.cpp Player.cpp
	$(CC) $(CFLAGS) -c Game.cpp Token.cpp Player.cpp