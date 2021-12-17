#pragma once

#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "components.h"
#include "../math/vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int h = SPRITE_DIM;
	int w = SPRITE_DIM;
	int scale = 1;

	int speed = SPRITE_SPEED;

	TransformComponent()
	{
		position.Zero();
	}

	TransformComponent(int mScale)
	{
		// place entity in the center of the screen
		position.x = SCREEN_W / 2;
		position.y = SCREEN_H / 2;
		scale = mScale;
	}

	TransformComponent(float mX, float mY)
	{
		position.x = mX;
		position.y = mY;
	}

	TransformComponent(float mX, float mY, int mH, int mW, int mScale)
	{
		position.x = mX;
		position.y = mY;

		h = mH;
		w = mW;
		scale = mScale;
	}

	void Init() override
	{
		velocity.Zero();
	}
};

#endif // !TRANSFORM_COMPONENT_H