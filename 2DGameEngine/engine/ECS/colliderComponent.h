#pragma once

#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <string>
#include "../global/defines.h"
#include "components.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	std::string tag;
	TransformComponent* transform;

	ColliderComponent() = default;
	ColliderComponent(std::string tag) {
		this->tag = tag;
	}

	void Init() override {
		// check to see that this entity actually has a Transform component, if not add
		if (!entity->HasComponent<TransformComponent>()) {
			entity->AddComponent<TransformComponent>();
		}

		transform = &entity->GetComponent<TransformComponent>();
	}

	void Update() override {
		// update colliders position and size each frame
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);

		collider.w = transform->w * transform->scale;
		collider.h = transform->h * transform->scale;
	}
};

#endif // !COLLIDER_COMPONENT_H