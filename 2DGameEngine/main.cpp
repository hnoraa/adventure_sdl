#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) 
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	if (game->init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, false) == -1) 
	{
		return -1;
	}

	while (game->running()) 
	{
		// get running time start for this frame
		frameStart = SDL_GetTicks();

		game->handleEvents();

		game->handleUpdates();

		game->handleRenders();

		// clock tick (frame time) - time in ms
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) 
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}