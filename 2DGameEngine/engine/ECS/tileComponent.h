#pragma once

#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include "components.h"
#include "../global/defines.h"
#include "../textureManager.h"
#include "../assetManager.h"

class TileComponent : public Component
{
public:
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;
	Vector2D position;
	
	TileComponent() = default;

	TileComponent(int mSrcX, int mSrcY, int mXPos, int mYPos, int mTileSize, int mTileScale, std::string mTextureId)
	{
		texture = Game::assets->GetTexture(mTextureId);

		srcRect.x = mSrcX;
		srcRect.y = mSrcY;
		srcRect.w = srcRect.h = mTileSize;

		position.x = static_cast<int>(mXPos);
		position.y = static_cast<int>(mYPos);

		destRect.w = destRect.h = mTileSize * mTileScale;
	}

	~TileComponent()
	{
		// don't do this here because the asset manager handles the textures
		// and this texture could be used by multiple objects
		// SDL_DestroyTexture(texture);
	}

	void Update() override
	{
		// update destination (x,y) given the position and camera
		destRect.x = static_cast<int>(position.x - Game::camera.x);
		destRect.y = static_cast<int>(position.y - Game::camera.y);
	}

	void Draw() override
	{
		TextureManager::DrawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};

#endif // !TILE_COMPONENT_H
