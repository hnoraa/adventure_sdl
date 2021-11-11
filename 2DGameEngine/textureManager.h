#pragma once

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "defines.h"
#include "game.h"

class TextureManager 
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

#endif // !TEXTURE_MANAGER_H