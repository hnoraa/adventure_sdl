#include "gameObject.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer)
{
	_renderer = renderer;
	_texture = TextureManager::loadTexture(textureSheet, renderer);
}

GameObject::~GameObject()
{
}

void GameObject::handleUpdates()
{
	_x = 10;
	_y = 10;

	_srcRect.h = 32;
	_srcRect.w = 32;
	_srcRect.x = 0;
	_srcRect.y = 0;

	_destRect.x = _x;
	_destRect.y = _y;

	// scale
	_destRect.w = _srcRect.w * 2;
	_destRect.h = _srcRect.h * 2;
}

void GameObject::handleRenders()
{
	SDL_RenderCopy(_renderer, _texture, &_srcRect, &_destRect);
}
