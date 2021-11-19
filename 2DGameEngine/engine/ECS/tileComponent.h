#pragma once

#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include "components.h"
#include "../global/defines.h"
#include "../textureManager.h"

class TileComponent : public Component {
public:
	TransformComponent* transform;
	SpriteComponent* sprite;
	SDL_Rect tileRect;
	int tileId;
	const char* path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id) {
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;

		tileId = id;

		switch (tileId) {
		case 0:
			path = T_ABYSS;
			break;
		case 1:
			path = T_DIRT;
			break;
		case 2:
			path = T_STONE;
			break;
		default:
			break;
		}
	}

	void Init() override {
		entity->AddComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->GetComponent<TransformComponent>();

		entity->AddComponent<SpriteComponent>(path);
		sprite = &entity->GetComponent<SpriteComponent>();
	}
};

#endif // !TILE_COMPONENT_H