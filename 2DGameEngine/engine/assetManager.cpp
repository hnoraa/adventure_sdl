#include "assetManager.h"
#include "ECS\components.h"

AssetManager::AssetManager(Manager* mManager) : _manager(mManager)
{
}

AssetManager::~AssetManager()
{

}

void AssetManager::CreateProjectile(Vector2D mPos, Vector2D mVel, int mRange, int mSpeed, std::string mId)
{
	// add to the entities
	auto& projectile(_manager->AddEntity());

	// give it some components
	projectile.AddComponent<TransformComponent>(mPos.x, mPos.y, TILE_DIM, TILE_DIM, 1);
	projectile.AddComponent<SpriteComponent>(mId, false);
	projectile.AddComponent<ProjectileComponent>(mRange, mSpeed, mVel);
	projectile.AddComponent<ColliderComponent>("projectile");

	// add to component group
	projectile.AddGroup(Game::G_PROJECTILES);
}

void AssetManager::AddTexture(std::string mId, const char* mTexturePath)
{
	// add the texture to the _textures map
	_textures.emplace(mId, TextureManager::LoadTexture(mTexturePath));
}

SDL_Texture* AssetManager::GetTexture(std::string mId)
{
	// return the specified texture
	return _textures[mId];
}