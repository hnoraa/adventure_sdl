#include "tileMap.h"
#include "textureManager.h"
#include "game.h"
#include <fstream>

TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

void TileMap::LoadMap(std::string mapFile, int sizeX, int sizeY)
{
	char tile;
	std::fstream stream;
	stream.open(mapFile);

	// parse the file
	for (int y = 0; y < sizeY; y++) 
	{
		for (int x = 0; x < sizeX; x++) 
		{
			// get the tile character
			stream.get(tile);

			// add to the game
			Game::AddTile(atoi(&tile), x * TILE_DIM, y * TILE_DIM);

			// ignore the comma
			stream.ignore();
		}
	}

	stream.close();
}

/*
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
*/