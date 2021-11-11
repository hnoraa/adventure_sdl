#pragma once

#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "../global/defines.h"
#include "components.h"
#include "../textureManager.h"

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		SetTexture(path);
	}

	void Init() override {
		// get a reference to the entities position component
		_transform = &entity->GetComponent<TransformComponent>();

		// set up the SDL rects
		_src.x = _src.y = 0;
		_src.w = _src.h = SPRITE_DIM;

		_dest.w = _dest.h = (SPRITE_DIM * 2);
	}

	void Update() override {
		// these are referenced from the postion components coordinates 
		_dest.x = (int)_transform->position.x;
		_dest.y = (int)_transform->position.y;
	}
	
	void Draw() override {
		TextureManager::DrawTexture(_texture, _src, _dest);
	}

	void SetTexture(const char *path) {
		_texture = TextureManager::LoadTexture(path);
	}
private:
	TransformComponent* _transform;
	SDL_Texture* _texture;
	SDL_Rect _src;
	SDL_Rect _dest;
};

#endif // !SPRITE_COMPONENT_H