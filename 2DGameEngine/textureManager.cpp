#include "textureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName, SDL_Renderer* renderer)
{
	SDL_Surface* temp = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);

	return tex;
}
