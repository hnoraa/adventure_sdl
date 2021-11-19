#pragma once

#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "components.h"
#include "../math/vector2D.h"

class TransformComponent : public Component {
public:
	Vector2D position;
	Vector2D velocity;

	int h = SPRITE_DIM;
	int w = SPRITE_DIM;
	int scale = 1;

	int speed = SPRITE_SPEED;

	TransformComponent() {
		position.Zero();
	}

	TransformComponent(int scale) {
		position.Zero();

		this->scale = scale;
	}

	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int scale) {
		position.x = x;
		position.y = y;

		this->h = h;
		this->w = w;
		this->scale = scale;
	}

	void Init() override {
		velocity.Zero();
	}

	void Update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};

#endif // !TRANSFORM_COMPONENT_H
