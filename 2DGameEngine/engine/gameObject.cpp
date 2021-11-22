#include "gameObject.h"

GameObject::GameObject(const char* mTextureSheet, int mX, int mY)
{
	_texture = TextureManager::LoadTexture(mTextureSheet);

	_x = mX;
	_y = mY;
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