#include "game.h"

TileMap* map;
GameObject* player;

SDL_Renderer* Game::renderer = nullptr;

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

	player = new GameObject(SPRITE_TEXTURE, TILE_DIM * 12, TILE_DIM * 2);
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
	player->HandleUpdates();
}

void Game::HandleRenders()
{
	// clear render buffer
	SDL_RenderClear(renderer);

	map->DrawMap();

	player->HandleRenders();

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
