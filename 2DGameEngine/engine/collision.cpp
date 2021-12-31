#include "collision.h"
#include "ECS\colliderComponent.h"

// Axis-Aligned Bounding-Box collision
bool Collision::AABB(const SDL_Rect& mA, const SDL_Rect& mB) 
{
	if (
		mA.x + mA.w >= mB.x &&
		mB.x + mB.w >= mA.x &&
		mA.y + mA.h >= mB.y &&
		mB.y + mB.h >= mA.y
		) 
	{
		return true;
	}

	return false;
}

bool Collision::AABB(const ColliderComponent& mA, ColliderComponent& mB)
{
	if (AABB(mA.collider, mB.collider)) 
	{
		return true;
	}
	else
	{
		return false;
	}
}