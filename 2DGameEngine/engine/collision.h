#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include "./global/defines.h"

class Collision {
public:
	// Axis-Aligned Bounding-Box collision
	static bool AABB(const SDL_Rect& a, const SDL_Rect& b);
};

#endif // !COLLISION_H
