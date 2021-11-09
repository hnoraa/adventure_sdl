#include "gameObject.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y)
{
	_renderer = renderer;
	_texture = TextureManager::loadTexture(textureSheet, _renderer);

	_x = x;
	_y = y;
}

GameObject::~GameObject()
{
}

void GameObject::handleUpdates()
{
	_x++;
	_y++;

	_srcRect.h = SPRITE_H;
	_srcRect.w = SPRITE_W;
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
