#include "game.h"
#include "textureManager.h"
#include "tileMap.h"
#include "./math/vector2D.h"
#include "ECS/components.h"
#include "collision.h"
#include "assetManager.h"


Manager manager;
TileMap* map;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::evt;
SDL_Rect Game::camera = { 0, 0, SCREEN_W, SCREEN_H };	// camera object
bool Game::isRunning = false;
auto& player(manager.AddEntity());						// create a player and add to the manager
AssetManager* Game::assets = new AssetManager(&manager);

Game::Game()
{
	isRunning = false;
	_window = nullptr;
}

Game::~Game()
{
	isRunning = false;
	SDL_Quit();
}

int Game::Init(const char* mTitle, int mX, int mY, int mW, int mH, bool mFullScreen)
{
	int flags = 0;

	if (mFullScreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR: Can't initialize subsystems..." << std::endl;
		return -1;
	}
	std::cout << "Subsystems Initialized..." << std::endl;

	_window = SDL_CreateWindow(mTitle, mX, mY, mW, mH, flags);
	if (!_window)
	{
		std::cout << "ERROR: Can't create window..." << std::endl;
		return -1;
	}
	std::cout << "Window Created..." << std::endl;

	renderer = SDL_CreateRenderer(_window, -1, 0);
	if (!renderer)
	{
		std::cout << "ERROR: Can't create renderer..." << std::endl;
		return -1;
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	std::cout << "Renderer Created..." << std::endl;

	isRunning = true;
	
	// add to asset manager
	assets->AddTexture("terrain", TILE_SHEET);
	assets->AddTexture("player", PLAYER_TEXTURE);
	assets->AddTexture("projectile", P_IMG_0);

	map = new TileMap("terrain", TILE_SCALE, TILE_DIM);
	map->LoadMap(MAP_FILE, MAP_W, MAP_H);

	// add components to the new player entity
	player.AddComponent<TransformComponent>(500.0f, 430.0f, TILE_DIM, TILE_DIM, 2);
	player.AddComponent<SpriteComponent>("player", true);
	player.AddComponent<KeyboardController>();
	player.AddComponent<ColliderComponent>("player");
	player.AddGroup(G_PLAYERS);

	// create a projectile
	assets->CreateProjectile(Vector2D(300, 300), Vector2D(2, 0), 800, 2, "projectile");
	assets->CreateProjectile(Vector2D(300, 310), Vector2D(2, 0), 800, 2, "projectile");
	assets->CreateProjectile(Vector2D(300, 320), Vector2D(2, 0), 800, 2, "projectile");
	assets->CreateProjectile(Vector2D(300, 340), Vector2D(2, 0), 800, 2, "projectile");

	return 0;
}

// create the group object lists for rendering
auto& lTiles(manager.GetGroup(Game::G_MAP));
auto& lPlayers(manager.GetGroup(Game::G_PLAYERS));
auto& lColliders(manager.GetGroup(Game::G_COLLIDERS));
auto& lEnemies(manager.GetGroup(Game::G_ENEMIES));
auto& lProjectiles(manager.GetGroup(Game::G_PROJECTILES));

void Game::HandleEvents()
{
	SDL_PollEvent(&evt);

	switch (evt.type)
	{
	default:
		break;
	}
}

void Game::HandleUpdates()
{
	SDL_Rect playerCollider = player.GetComponent<ColliderComponent>().collider;
	Vector2D playerColliderPosition = player.GetComponent<TransformComponent>().position;

	manager.Refresh();
	manager.Update();

	for (auto& c : lColliders)
	{
		SDL_Rect cCol = c->GetComponent<ColliderComponent>().collider;

		if (Collision::AABB(cCol, playerCollider))
		{
			player.GetComponent<TransformComponent>().position = playerColliderPosition;
			std::cout << "Collision" << std::endl;
		}
	}

	for (auto& p : lProjectiles)
	{
		if (Collision::AABB(player.GetComponent<ColliderComponent>().collider, p->GetComponent<ColliderComponent>().collider))
		{
			std::cout << "Projectile hit player" << std::endl;

			// "delete" the projectile, this is where we'd add in health and stuff (i.e. damage, etc)
			p->Destroy();
		}
	}

	// position the camera
	camera.x = static_cast<int>(player.GetComponent<TransformComponent>().position.x - (SCREEN_W / 2));
	camera.y = static_cast<int>(player.GetComponent<TransformComponent>().position.y - (SCREEN_H / 2));

	// check bounds of the camera
	if (camera.x < 0)
	{
		camera.x = 0;
	}

	if (camera.x > camera.w)
	{
		camera.x = camera.w;
	}

	if (camera.y < 0)
	{
		camera.y = 0;
	}

	if (camera.y > camera.h)
	{
		camera.y = camera.h;
	}
}

void Game::HandleRenders()
{
	// clear render buffer
	SDL_RenderClear(renderer);

	// draw the object lists from the groups
	// draw tiles (map)
	for (auto& mX : lTiles)
	{
		mX->Draw();
	}

	// draw colliders
	for (auto& mX : lColliders)
	{
		mX->Draw();
	}

	// draw players
	for (auto& mX : lPlayers)
	{
		mX->Draw();
	}

	// draw enemies
	for (auto& mX : lEnemies)
	{
		mX->Draw();
	}

	// draw projectiles
	for (auto& mX : lProjectiles)
	{
		mX->Draw();
	}

	// present renderer
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();

	std::cout << "Game Cleaned..." << std::endl;
}