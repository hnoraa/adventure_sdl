#include "gameObject.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	_texture = TextureManager::LoadTexture(textureSheet);

	_x = x;
	_y = y;
}

GameObject::~GameObject()
{
}

void GameObject::HandleUpdates()
{
	_srcRect.h = SPRITE_DIM;
	_srcRect.w = SPRITE_DIM;
	_srcRect.x = 0;
	_srcRect.y = 0;

	_destRect.x = _x;
	_destRect.y = _y;

	// scale
	_destRect.w = _srcRect.w * 2;
	_destRect.h = _srcRect.h * 2;
}

void GameObject::HandleRenders()
{
	SDL_RenderCopy(Game::renderer, _texture, &_srcRect, &_destRect);
}