#pragma once

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <string>
#include "textureManager.h"
#include "math/vector2D.h"
#include "ECS/ECS.h"

class AssetManager
{
public:
	AssetManager(Manager *mManager);
	~AssetManager();

	// game objects
	void CreateProjectile(Vector2D mPos, Vector2D mVel, int mRange, int mSpeed, std::string mId);

	// texture management
	void AddTexture(std::string mId, const char* mTexturePath);
	SDL_Texture* GetTexture(std::string mId);
private:
	Manager* _manager;
	std::map<std::string, SDL_Texture*> _textures;
};

#endif // !ASSET_MANAGER_H