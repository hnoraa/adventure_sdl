#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include "./global/defines.h"

// forward declaration of ColliderComponent because it's not compiled at this point
class ColliderComponent;

class Collision 
{
public:
	// Axis-Aligned Bounding-Box collision
	static bool AABB(const SDL_Rect& mA, const SDL_Rect& mB);
	static bool AABB(const ColliderComponent& mA, ColliderComponent& mB);
};

#endif // !COLLISION_H