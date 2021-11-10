#include "tileMap.h"

/**
* Level 1 - Default map, will be loaded from a file at some point
* 0 = abyss
* 1 = dirt
* 2 = stone
**/
int lvl1[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,0,0},
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
	{0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0}
};

TileMap::TileMap()
{
	_abyss = TextureManager::LoadTexture(T_ABYSS);
	_dirt = TextureManager::LoadTexture(T_DIRT);
	_stone = TextureManager::LoadTexture(T_STONE);

	LoadMap(lvl1);

	// coordinates
	_src.x = _src.y = 0;
	_dest.x = _dest.y = 0;

	// dimensions
	_src.w = _src.h = TILE_DIM;
	_dest.w = _dest.h = TILE_DIM;
}

TileMap::~TileMap()
{
}

void TileMap::LoadMap(int mapArray[20][25])
{
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			_map[row][col] = mapArray[row][col];
		}
	}
}

void TileMap::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 25; col++) {
			type = _map[row][col];

			// map tiles
			_dest.x = col * TILE_DIM;
			_dest.y = row * TILE_DIM;

			switch (type) {
			case 0:
				// abyss
				TextureManager::Draw(_abyss, _src, _dest);
				break;
			case 1:
				// dirt
				TextureManager::Draw(_dirt, _src, _dest);
				break;
			case 2:
				// stone
				TextureManager::Draw(_stone, _src, _dest);
				break;
			};

		}
	}
}
