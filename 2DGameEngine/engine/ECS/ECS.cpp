#include "ECS.h"

void Entity::AddGroup(Group mGroup)
{
	_groupBitSet[mGroup] = true;
	_manager.AddToGroup(this, mGroup);
}