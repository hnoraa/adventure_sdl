#pragma once

#ifndef GAME_H
#define GAME_H

#include "global/defines.h"
#include <vector>

class ColliderComponent;	// forward declaration of ColliderComponent because it's not compiled at this point

class Game
{
public:
	Game();
	~Game();

	int Init(const char* mTitle, int mX, int mY, int mW, int mH, bool mFullScreen);
	void HandleEvents();
	void HandleUpdates();
	void HandleRenders();
	void Clean();
	bool Running() 
	{
		return isRunning;
	}

	static SDL_Renderer* renderer;
	static SDL_Event evt;
	static bool isRunning;
	static SDL_Rect camera;								// the camera is just an SDL rectangle that is basicallty the "viewport"
	enum groupLabels : std::size_t						// group label enum
	{
		G_MAP,
		G_PLAYERS,
		G_ENEMIES,
		G_COLLIDERS
	};
private:
	SDL_Window* _window;
};

#endif // !GAME_H
