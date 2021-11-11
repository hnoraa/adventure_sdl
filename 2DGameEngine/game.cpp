#include "game.h"
#include "textureManager.h"
#include "tileMap.h"
#include "./math/vector2D.h"
#include "ECS/components.h"

TileMap* map;

SDL_Renderer* Game::renderer = nullptr;
Manager manager;
auto& player(manager.AddEntity());	// create a player and add to the manager

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

	// add position component to the new player entity
	player.AddComponent<TransformComponent>(TILE_DIM * 12, TILE_DIM * 2);
	player.AddComponent<SpriteComponent>(PLAYER_TEXTURE);

	return 0;
}

void Game::HandleEvents()
{
	SDL_Event evt;
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

	player.GetComponent<TransformComponent>().position.Add(Vector2D(5, 0));

	//std::cout << player.GetComponent<TransformComponent>().position. << std::endl;
	if (player.GetComponent<TransformComponent>().position.x > 100) {
		player.GetComponent<SpriteComponent>().SetTexture(PLAYER_TEXTURE);
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