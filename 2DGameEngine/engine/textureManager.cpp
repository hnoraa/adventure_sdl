#include "textureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* mFileName)
{
	SDL_Surface* temp = IMG_Load(mFileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, temp);
	SDL_FreeSurface(temp);

	return tex;
}

void TextureManager::DrawTexture(SDL_Texture* mTexture, SDL_Rect mSrc, SDL_Rect mDest, SDL_RendererFlip mFlip)
{
	// RenderCopyEx allows you to flip the sprite
	SDL_RenderCopyEx(Game::renderer, mTexture, &mSrc, &mDest, NULL, NULL, mFlip);
}