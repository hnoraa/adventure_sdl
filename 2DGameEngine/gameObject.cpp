#include "gameObject.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer)
{
	_renderer = renderer;
}

GameObject::~GameObject()
{
}

void GameObject::handleUpdates()
{
}

void GameObject::handleRenders()
{
}
