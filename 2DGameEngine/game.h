#pragma once

#ifndef GAME_H
#define GAME_H

#include "defines.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	// init SDL window
	int init(const char* title, int x, int y, int w, int h, bool fullScreen);

	// game loop components
	void handleEvents();
	void handleUpdates();
	void handleRenders();

	// GC
	void clean();

	bool running() 
	{
		return _running;
	}

private:
	bool _running;

	SDL_Window* _window;
	SDL_Renderer* _renderer;
};
#endif // !GAME_H


