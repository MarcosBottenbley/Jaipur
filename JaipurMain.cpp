#include "Game.h"

int main() {
	Game game;
	game.startGame();		//get player names.

	for (int i = 0; i < 3; i++) {
		game.startRound();
		game.playGame();
		if (game.endRound())
			break;
	}
	game.endGame();
	return 0;
}

