#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "defines.h"

class TextureManager 
{
public:
	static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer);
};
#endif // !TEXTURE_MANAGER_H
