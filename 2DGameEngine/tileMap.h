#pragma once
#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "defines.h"
#include "game.h"
#include "textureManager.h"

class TileMap
{
public:
	TileMap();
	~TileMap();

	void LoadMap(int mapArray[20][25]);
	void DrawMap();

private:
	SDL_Rect _src;
	SDL_Rect _dest;

	// tile textures
	SDL_Texture* _abyss;
	SDL_Texture* _dirt;
	SDL_Texture* _stone;

	int _map[20][25];
};

#endif // !TILE_MAP_H
