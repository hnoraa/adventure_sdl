#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#ifdef _WIN32
#include "SDL.h"
#include "SDL_image.h"
#else
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#endif

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* renderer);
};
#endif // !TEXTURE_MANAGER_H
