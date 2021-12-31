#pragma once

#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <string>
#include "../global/defines.h"
#include "components.h"

class ColliderComponent : public Component
{
public:
	SDL_Rect collider;
	std::string tag;
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

	ColliderComponent(std::string mTag)
	{
		tag = mTag;
	}

	ColliderComponent(std::string mTag, int mXPos, int mYPos, int mSize)
	{
		tag = mTag;
		collider = { mXPos, mYPos, mSize, mSize };
	}

	void Init() override
	{
		// check to see that this entity actually has a Transform component, if not add
		if (!entity->HasComponent<TransformComponent>())
		{
			entity->AddComponent<TransformComponent>();
		}

		transform = &entity->GetComponent<TransformComponent>();

		// load the texture and set the SDL rects for the texture
		texture = TextureManager::LoadTexture(TILE_COLLIDE_TEXTURE);
		srcRect = { 0, 0, TILE_DIM, TILE_DIM };
		destRect = { collider.x, collider.y, collider.w, collider.h };
	}

	void Update() override
	{
		if (tag != "terrain")
		{
			// update colliders position and size each frame
			collider.x = static_cast<int>(transform->position.x);
			collider.y = static_cast<int>(transform->position.y);
			collider.w = transform->w * transform->scale;
			collider.h = transform->h * transform->scale;
		}

		// update the destination rect
		destRect.x = collider.x - Game::camera.x;
		destRect.y = collider.y - Game::camera.y;
	}

	void Draw() override
	{
		TextureManager::DrawTexture(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};

#endif // !COLLIDER_COMPONENT_H
