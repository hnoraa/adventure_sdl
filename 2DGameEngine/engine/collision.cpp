#include "collision.h"

// Axis-Aligned Bounding-Box collision
bool Collision::AABB(const SDL_Rect& a, const SDL_Rect& b) {
	if ((a.x + a.w) >= b.x 
		&& (b.x + b.w) >= a.x 
		&& (a.y + a.h) >= b.y 
		&& (b.y + b.h) >= b.y) {
		return true;
	}

	// no collision
	return false;
}