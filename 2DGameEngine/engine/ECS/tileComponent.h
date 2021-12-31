#pragma once

#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include "components.h"
#include "../global/defines.h"
#include "../textureManager.h"

class TileComponent : public Component
{
public:
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	Vector2D position;
	
	TileComponent() = default;

	TileComponent(int mSrcX, int mSrcY, int mXPos, int mYPos, const char * mFilePath)
	{
		texture = TextureManager::LoadTexture(mFilePath);
		
		position.x = mXPos;
		position.y = mYPos;

		srcRect.x = mSrcX;
		srcRect.y = mSrcY;
		srcRect.w = 32;
		srcRect.h = 32;

		destRect.x = mXPos;
		destRect.y = mYPos;
		destRect.w = (32 * 2);
		destRect.h = (32 * 2);
	}

	void Update() override
	{
		// update destination (x,y) given the position and camera
		destRect.x = position.x - Game::camera.x;
		destRect.y = position.y - Game::camera.y;
	}

	void Draw() override
	{
		TextureManager::DrawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
	}

	~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}
};

#endif // !TILE_COMPONENT_H