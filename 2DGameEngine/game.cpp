#include "game.h"
#include "textureManager.h"

SDL_Texture* playerTexture;
SDL_Rect srcRect, destRect;

Game::Game()
{
	_running = false;
	_window = NULL;
	_renderer = NULL;
	_counter = 0;
}

Game::~Game()
{
	_running = false;
	SDL_Quit();
}

int Game::init(const char* title, int x, int y, int w, int h, bool fullScreen)
{
	int flags = 0;

	if (fullScreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "ERROR: Can't initialize subsystems..." << std::endl;
		return -1;
	}

	std::cout << "Subsystems Initialized..." << std::endl;

	_window = SDL_CreateWindow(title, x, y, w, h, flags);

	if (!_window) {
		std::cout << "ERROR: Can't create window..." << std::endl;
		return -1;
	}
	std::cout << "Window Created..." << std::endl;

	_renderer = SDL_CreateRenderer(_window, -1, 0);

	if (!_renderer) {
		std::cout << "ERROR: Can't create renderer..." << std::endl;
		return -1;
	}

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

	std::cout << "Renderer Created..." << std::endl;

	playerTexture = TextureManager::loadTexture("res/imgs/tester.png", _renderer);

	_running = true;
}

void Game::handleEvents()
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

void Game::handleUpdates()
{
	_counter++;

	// scale for player texture
	destRect.h = 32;
	destRect.w = 32;
	destRect.x = _counter;

	std::cout << _counter << std::endl;

	if (_counter >= 578) _counter = 32;
}

void Game::handleRenders()
{
	// clear render buffer
	SDL_RenderClear(_renderer);

	// add rendering items here
	SDL_RenderCopy(_renderer, playerTexture, NULL, &destRect);

	// present renderer
	SDL_RenderPresent(_renderer);
}

void Game::clean()
{
	SDL_DestroyTexture(playerTexture);

	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();

	std::cout << "Game Cleaned..." << std::endl;
}
