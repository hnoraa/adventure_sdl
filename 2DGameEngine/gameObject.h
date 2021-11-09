#pragma once

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "defines.h"

class GameObject
{
public:
	GameObject(const char *textureSheet, SDL_Renderer *renderer);
	~GameObject();

	void handleUpdates();
	void handleRenders();
private:
	int _x;
	int _y;

	SDL_Texture* _texture;
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
	SDL_Renderer* _renderer;
};
#endif // !GAME_OBJECT_H