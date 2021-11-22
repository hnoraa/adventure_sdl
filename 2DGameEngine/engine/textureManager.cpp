#include "textureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* mFileName)
{
	SDL_Surface* temp = IMG_Load(mFileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, temp);
	SDL_FreeSurface(temp);

	return tex;
}

void TextureManager::DrawTexture(SDL_Texture* mTexture, SDL_Rect mSrc, SDL_Rect mDest)
{
	SDL_RenderCopy(Game::renderer, mTexture, &mSrc, &mDest);
}