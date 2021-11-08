#pragma once

#ifndef GAME_H
#define GAME_H

#ifdef _WIN32
#include "SDL.h"
#include "SDL_image.h"
#else
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#endif

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

	bool running() {
		return _running;
	}

private:
	bool _running;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	int _counter;
};
#endif // !GAME_H


