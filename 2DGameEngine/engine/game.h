#pragma once

#ifndef GAME_H
#define GAME_H

#include "global/defines.h"
#include <vector>

// forward declaration of ColliderComponent because it's not compiled at this point
class ColliderComponent;

class Game
{
public:
	Game();
	~Game();

	// init SDL window
	int Init(const char* mTitle, int mX, int mY, int mW, int mH, bool mFullScreen);

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

	static void AddTile(int mId, int mX, int mY);

	static SDL_Renderer* renderer;
	static SDL_Event evt;

	static std::vector<ColliderComponent*> colliders;
private:
	bool _running;

	SDL_Window* _window;
};

#endif // !GAME_H