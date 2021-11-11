#pragma once

#ifndef GAME_H
#define GAME_H


#include "defines.h"
#include "textureManager.h"
#include "tileMap.h"
#include "ECS/components.h"

class Game
{
public:
	Game();
	~Game();

	// init SDL window
	int Init(const char* title, int x, int y, int w, int h, bool fullScreen);

	// game loop components
	void HandleEvents();
	void HandleUpdates();
	void HandleRenders();

	// GC
	void Clean();

	bool Running() 
	{
		return _running;
	}

	static SDL_Renderer* renderer;
private:
	bool _running;

	SDL_Window* _window;
};

#endif // !GAME_H