#pragma once

#ifndef ECS_H
#define ECS_H

#include "../global/defines.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

// forward class defs so the compiler knows these classes exist but havent been defined yet
class Component;
class Entity;
class Manager;

// create a ComponentID type that is of std::size_t
// this will be used to identify all components
using ComponentID = std::size_t;
using Group = std::size_t;

// puts this function code where we use the function
inline ComponentID GetNewComponentTypeID()
{
	// setting it to static will remember what the last value of it is
	// 1st time 1, 2nd time 2 etc...
	static ComponentID lastID = 0u;	// unsigned
	return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept
{
	static ComponentID typeID = GetNewComponentTypeID(); // generates a new lastID
	return typeID;
}

// number of components an entity can hold
constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using ComponentBitSet = std::bitset<maxComponents>;	// find if an entity has a selection of components
using ComponentArray = std::array<Component*, maxComponents>;	// array of component pointers
using GroupBitSet = std::bitset<maxGroups>;	// find if an entity has a selection of groups

class Component
{
public:
	Entity* entity;	// reference to its owner

	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() {}

	virtual ~Component() {}
};

class Entity
{
public:
	Entity(Manager& mManager): _manager(mManager) {}

	void Update()
	{
		// loop through entities components vector
		for (auto& c : _components)
		{
			c->Update();
		}
	}

	void Draw()
	{
		// loop through entities components vector
		for (auto& c : _components)
		{
			c->Draw();
		}
	}

	bool IsActive() const
	{
		return _active;
	}

	void Destroy()
	{
		_active = false;	// removed
	}

	bool HasGroup(Group mGroup)
	{
		// does the bitset contain this group
		return _groupBitSet[mGroup];
	}

	void AddGroup(Group mGroup);

	void RemoveGroup(Group mGroup)
	{
		// the manager will check for falses in the group bit set and remove them
		_groupBitSet[mGroup] = false;
	}

	template <typename T> bool HasComponent() const
	{
		// query the entity to see if it has components
		// of type T
		return _componentBitSet[GetComponentTypeID<T>()];
	}

	// this function returns a reference to T (designation: T&)
	template <typename T, typename... TArgs> T& AddComponent(TArgs&&... mArgs)
	{
		// create a new component
		T* c(new T(std::forward<TArgs>(mArgs)...));

		// register it to this entity
		c->entity = this;

		// add the component to the entities components vector
		std::unique_ptr<Component> uPtr{ c };
		_components.emplace_back(std::move(uPtr));

		// this is the index of the component
		_componentArray[GetComponentTypeID<T>()] = c;

		// add to component BitSet
		_componentBitSet[GetComponentTypeID<T>()] = true;

		// call the components Init function
		c->Init();
		return *c;
	}

	// this function returns a reference to T (designation: T&)
	template <typename T> T& GetComponent() const
	{
		// set a pointer to the position in the componentArray
		auto ptr(_componentArray[GetComponentTypeID<T>()]);

		return *static_cast<T*>(ptr);
	}
private:
	Manager& _manager;
	bool _active = true;	// false - remove it from the game
	std::vector<std::unique_ptr<Component>> _components;
	ComponentArray _componentArray;
	ComponentBitSet _componentBitSet;
	GroupBitSet _groupBitSet;
};

// manages entities
class Manager
{
public:
	void Update()
	{
		// run the update functions of all entities
		for (auto& e : _entities)
		{
			e->Update();
		}
	}

	void Draw()
	{
		// run the draw functions of all entities
		for (auto& e : _entities)
		{
			e->Draw();
		}
	}

	void Refresh()
	{
		// loop through grouped entities and remove and falses
		for (auto i(0u); i < maxGroups; i++)
		{
			auto& v(_groupedEntities[i]);
			v.erase(std::remove_if(std::begin(v), std::end(v), [i](Entity* mEntity)
				{
					return !mEntity->IsActive() || !mEntity->HasGroup(i);
				}), std::end(v));
		}

		// loop through all entities and remove if not active
		_entities.erase(std::remove_if(std::begin(_entities), std::end(_entities), [](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->IsActive();
			}), std::end(_entities));
	}

	void AddToGroup(Entity* mEntity, Group mGroup)
	{
		// add the entity to the group
		_groupedEntities[mGroup].emplace_back(mEntity);
	}

	std::vector<Entity*>& GetGroup(Group mGroup)
	{
		// return the group from _groupedEntities
		return _groupedEntities[mGroup];
	}

	Entity& AddEntity()
	{
		// add a new entity and return the reference to it
		Entity* e = new Entity(*this);	// when an entity is created, it has a reference to this Manager class 
		std::unique_ptr<Entity> uPtr{ e };	// create a unique pointer initialized to e (Entity pointer)
		_entities.emplace_back(std::move(uPtr));

		return *e;
	}
private:
	std::vector<std::unique_ptr<Entity>> _entities;	// vector that holds all of the entities
	std::array<std::vector<Entity*>, maxGroups> _groupedEntities;
};

#endif // !ECS_H
