#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {
	game = new Game();

	if (game->init("Adventure", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, true) == -1) {
		return -1;
	}

	while (game->running()) {
		game->handleEvents();

		game->handleUpdates();

		game->handleRenders();

		// clock tick
	}

	game->clean();

	return 0;
}