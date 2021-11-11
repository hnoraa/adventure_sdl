#pragma once

#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "components.h"
#include "../math/vector2D.h"

class TransformComponent : public Component {
public:
	Vector2D position;
	Vector2D velocity;

	int speed = SPRITE_SPEED;

	TransformComponent() {
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	void Init() override {
		velocity.x = 0;
		velocity.y = 0;
	}

	void Update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};

#endif // !TRANSFORM_COMPONENT_H