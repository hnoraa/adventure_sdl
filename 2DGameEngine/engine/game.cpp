#include "game.h"
#include "textureManager.h"
#include "tileMap.h"
#include "./math/vector2D.h"
#include "ECS/components.h"
#include "collision.h"

// statics
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::evt;

// acces to colliders vector (the game collision components)
std::vector<ColliderComponent*> Game::colliders;

bool Game::isRunning = false;

Manager manager;
auto& player(manager.AddEntity());	// create a player and add to the manager
auto& wall(manager.AddEntity());	// wall to collide with

// group label enum
enum groupLabels : std::size_t
{
	MAP,
	PLAYERS,
	ENEMIES,
	COLLIDERS
};

// create the group object lists for rendering
auto& lTiles(manager.GetGroup(MAP));
auto& lPlayers(manager.GetGroup(PLAYERS));
auto& lEnemies(manager.GetGroup(ENEMIES));
auto& lColliders(manager.GetGroup(COLLIDERS));

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

	// add components to the new player entity
	TileMap::LoadMap(MAP_FILE, MAP_W, MAP_H);

	player.AddComponent<TransformComponent>(2);
	player.AddComponent<SpriteComponent>(PLAYER_TEXTURE, true);
	player.AddComponent<KeyboardController>();
	player.AddComponent<ColliderComponent>("player");
	player.AddGroup(PLAYERS);

	return 0;
}

void Game::AddTile(int mSrcX, int mSrcY, int mXPos, int mYPos)
{
	auto& tile(manager.AddEntity());
	tile.AddComponent<TileComponent>(mSrcX, mSrcY, mXPos, mYPos, TILE_SHEET);
	tile.AddGroup(MAP);
}

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
	manager.Refresh();
	manager.Update();

	// scroll the map as the player moves
	Vector2D playerVelocity = player.GetComponent<TransformComponent>().velocity;
	int playerSpeed = player.GetComponent<TransformComponent>().speed;

	for (auto tile : lTiles)
	{
		tile->GetComponent<TileComponent>().destRect.x += -(playerVelocity.x * playerSpeed);
		tile->GetComponent<TileComponent>().destRect.y += -(playerVelocity.y * playerSpeed);
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

	// draw colliders
	for (auto& mX : colliders)
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