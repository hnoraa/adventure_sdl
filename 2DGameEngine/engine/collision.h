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
	static bool AABB(const SDL_Rect& a, const SDL_Rect& b);
	static bool AABB(const ColliderComponent& a, ColliderComponent& b);
};

#endif // !COLLISION_H