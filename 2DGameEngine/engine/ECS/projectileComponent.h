#pragma once

#ifndef PROJECTILE_COMPONENT_H
#define PROJECTILE_COMPONENT_H

#include "components.h"
#include "../math/vector2D.h"

class ProjectileComponent: public Component
{
public:
	ProjectileComponent(int mRange, int mSpeed, Vector2D mVelocity) : _range(mRange), _speed(mSpeed), _velocity(mVelocity)
	{
	}

	~ProjectileComponent() {}

	void Init() override
	{
		_transform = & entity->GetComponent<TransformComponent>();
		_transform->velocity = _velocity;
	}

	void Update() override
	{
		_distance += _speed;

		// is the projectile out of range?
		if (_distance > _range)
		{
			std::cout << "Out of range (" << _distance << ")" << std::endl;
			entity->Destroy();
		}
		else if(_transform->position.x > Game::camera.x + Game::camera.w ||
				_transform->position.x < Game::camera.x ||
				_transform->position.y > Game::camera.y + Game:: camera.h ||
				_transform->position.y < Game::camera.y)
		{
			// out of the screen
			std::cout << "Out of bounds" << std::endl;
			entity->Destroy();
		}
	}
private:
	TransformComponent* _transform;
	int _range = 0;
	int _speed = 0;
	int _distance = 0;	// see how far it has travelled
	Vector2D _velocity;
};
#endif // !PROJECTILE_COMPONENT_H
