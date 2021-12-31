#pragma once

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "global/defines.h"
#include "game.h"

class TextureManager 
{
public:
	static SDL_Texture* LoadTexture(const char* mFileName);
	static void DrawTexture(SDL_Texture* mTexture, SDL_Rect mSrc, SDL_Rect mDest, SDL_RendererFlip mFlip);
};

#endif // !TEXTURE_MANAGER_H
