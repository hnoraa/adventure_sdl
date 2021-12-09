#pragma once

#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "../global/defines.h"
#include "components.h"
#include "../textureManager.h"
#include "animation.h"
#include <map>

class SpriteComponent : public Component
{
public:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
	int animationIndex = 0;	// where on the sprite sheet we are (height based, each animation is horizontal and they are stacked vertically)
	std::map<const char*, Animation> animations;

	SpriteComponent() = default;

	SpriteComponent(const char* mPath)
	{
		SetTexture(mPath);
	}

	SpriteComponent(const char* mPath, bool mAnimated)
	{
		_animated = mAnimated;

		// create the animations
		Animation idleFront = Animation(0, 3, 300, 0);
		Animation idleBack = Animation(0, 3, 300, 3);
		Animation walk = Animation(1, 8, 300, 0);

		animations.emplace("idleFront", idleFront);
		animations.emplace("idleBack", idleBack);
		animations.emplace("walk", walk);

		Play("idleBack");

		SetTexture(mPath);
	}

	~SpriteComponent()
	{
		SDL_DestroyTexture(_texture);
	}

	void Init() override
	{
		// get a reference to the entities position component
		_transform = &entity->GetComponent<TransformComponent>();

		// set up the SDL rects
		_src.x = _src.y = 0;
		_src.w = _transform->w;
		_src.h = _transform->h;

		_dest.w = _transform->w;
		_dest.h = _transform->h;
	}

	void Update() override
	{
		if (_animated)
		{
			// if _frames = 4, then the % operator will cycle through 1, 2, 3, 4 at the _speed variable
			// added: (_xOffset * SPRITE_DIM), this gets the horizontal beginning of the animation
			_src.x = (_xOffset * SPRITE_DIM) + (_src.w * static_cast<int>((SDL_GetTicks() / _speed) % _frames));
		}

		_src.y = animationIndex * _transform->h;

		// these are referenced from the postion components coordinates 
		_dest.x = static_cast<int> (_transform->position.x);
		_dest.y = static_cast<int> (_transform->position.y);

		_dest.w = _transform->w * _transform->scale;
		_dest.h = _transform->h * _transform->scale;
	}

	void Draw() override
	{
		TextureManager::DrawTexture(_texture, _src, _dest, spriteFlip);
	}

	void SetTexture(const char* mPath)
	{
		_texture = TextureManager::LoadTexture(mPath);
	}

	void Play(const char* mAnimationName)
	{
		// change the current frames and index for the animation
		_frames = animations[mAnimationName].frames;
		_speed = animations[mAnimationName].speed;
		_xOffset = animations[mAnimationName].xOffset;
		animationIndex = animations[mAnimationName].index;
	}
private:
	TransformComponent* _transform;
	SDL_Texture* _texture;
	SDL_Rect _src;
	SDL_Rect _dest;

	bool _animated = false;
	int _frames = 0;
	int _xOffset = 0;
	int _speed = 500;	// delay between frames in ms
};

#endif // !SPRITE_COMPONENT_H