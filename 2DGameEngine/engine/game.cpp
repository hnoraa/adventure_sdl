#include "game.h"
#include "textureManager.h"
#include "tileMap.h"
#include "./math/vector2D.h"
#include "ECS/components.h"
#include "collision.h"

TileMap* map;

// statics
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::evt;

Manager manager;
auto& player(manager.AddEntity());	// create a player and add to the manager
auto& wall(manager.AddEntity());	// wall to collide with

Game::Game()
{
	_running = false;
	_window = nullptr;
}

Game::~Game()
{
	_running = false;
	SDL_Quit();
}

int Game::Init(const char* title, int x, int y, int w, int h, bool fullScreen)
{
	int flags = 0;

	if (fullScreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR: Can't initialize subsystems..." << std::endl;
		return -1;
	}

	std::cout << "Subsystems Initialized..." << std::endl;

	_window = SDL_CreateWindow(title, x, y, w, h, flags);

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

	_running = true;

	map = new TileMap();

	// add components to the new player entity
	player.AddComponent<TransformComponent>(2);
	player.AddComponent<SpriteComponent>(PLAYER_TEXTURE);
	player.AddComponent<KeyboardController>();
	player.AddComponent<ColliderComponent>("player");

	// wall components
	wall.AddComponent<TransformComponent>(300.0f, 300.0f, 280, 20, 1);
	wall.AddComponent<SpriteComponent>(DEBUG_TEXTURE);
	wall.AddComponent<ColliderComponent>("wall");

	return 0;
}

void Game::HandleEvents()
{
	SDL_PollEvent(&evt);

	switch (evt.type) {
	case SDL_QUIT:
		_running = false;
		break;
	default:
		break;
	}
}

void Game::HandleUpdates()
{
	manager.Refresh();
	manager.Update();

	if (Collision::AABB(player.GetComponent<ColliderComponent>().collider, wall.GetComponent<ColliderComponent>().collider)) {
		player.GetComponent<TransformComponent>().scale = 1;
		std::cout << "Wall hit!" << std::endl;
	}
}

void Game::HandleRenders()
{
	// clear render buffer
	SDL_RenderClear(renderer);

	map->DrawMap();
	manager.Draw();

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