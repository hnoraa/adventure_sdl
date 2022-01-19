// Based off of: https://github.com/carlbirch/BirchEngine/blob/master/BirchEngine/Src/ECS/ECS.h
// And: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
#include "engine/game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	// FPS calculations and vars
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	game = new Game();

	if (game->Init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, FULLSCREEN) == -1)
	{
		return -1;
	}

	while (game->Running())
	{
		// get running time start for this frame
		frameStart = SDL_GetTicks();

		game->HandleEvents();

		game->HandleUpdates();

		game->HandleRenders();

		// clock tick (frame time) - time in ms
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->Clean();

	return 0;
}