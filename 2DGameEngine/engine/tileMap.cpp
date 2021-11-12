#include "tileMap.h"
#include "textureManager.h"

/**
* Level 1 - Default map, will be loaded from a file at some point
* 0 = abyss
* 1 = dirt
* 2 = stone
**/
int lvl1[MAP_H][MAP_W] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0},
	{0,0,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,0,0},
	{0,0,0,0,0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0}
};

TileMap::TileMap()
{
	_abyss = TextureManager::LoadTexture(T_ABYSS);
	_dirt = TextureManager::LoadTexture(T_DIRT);
	_stone = TextureManager::LoadTexture(T_STONE);

	LoadMap(lvl1);
	FlipMap(lvl1);

	// coordinates
	_src.x = _src.y = 0;
	_dest.x = _dest.y = 0;

	// dimensions
	_src.w = _src.h = TILE_DIM;
	_dest.w = _dest.h = TILE_DIM;
}

TileMap::~TileMap()
{
	SDL_DestroyTexture(_abyss);
	SDL_DestroyTexture(_dirt);
	SDL_DestroyTexture(_stone);
}

void TileMap::LoadMap(int mapArray[MAP_H][MAP_W])
{
	for (int row = 0; row < MAP_H; row++) {
		for (int col = 0; col < MAP_W; col++) {
			_map[row][col] = mapArray[row][col];
		}
	}
}

void TileMap::FlipMap(int mapArray[MAP_H][MAP_W]) {
	for (int row = 0; row < MAP_H; row++) {
		for (int col = 0; col < MAP_W; col++) {
			_map[row][col] = mapArray[(MAP_H - 1) - row][(MAP_W - 1) - col];
		}
	}
}

void TileMap::DrawMap()
{
	int type = 0;

	for (int row = 0; row < MAP_H; row++) {
		for (int col = 0; col < MAP_W; col++) {
			type = _map[row][col];

			// map tiles
			_dest.x = col * TILE_DIM;
			_dest.y = row * TILE_DIM;

			switch (type) {
			case 0:
				// abyss
				TextureManager::DrawTexture(_abyss, _src, _dest);
				break;
			case 1:
				// dirt
				TextureManager::DrawTexture(_dirt, _src, _dest);
				break;
			case 2:
				// stone
				TextureManager::DrawTexture(_stone, _src, _dest);
				break;
			default:
				break;
			};
		}
	}
}