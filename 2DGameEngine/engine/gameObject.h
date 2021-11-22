#pragma once

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "global/defines.h"
#include "game.h"
#include "textureManager.h"

class GameObject
{
public:
	GameObject(const char *mTextureSheet, int mX, int mY);
	~GameObject();

	void HandleUpdates();
	void HandleRenders();
private:
	int _x;
	int _y;

	SDL_Texture* _texture;
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
};

#endif // !GAME_OBJECT_H