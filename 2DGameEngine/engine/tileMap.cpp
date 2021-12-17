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

void TileMap::LoadMap(std::string mMapFile, int mSizeX, int mSizeY)
{
	char tileChar;
	std::fstream stream;
	stream.open(mMapFile);

	int srcX;
	int srcY;

	// parse the file
	for (int y = 0; y < mSizeY; y++) 
	{
		for (int x = 0; x < mSizeX; x++) 
		{
			// tile comes in as two digits (ex: 00)
			// first digit is Y
			// second is X
			stream.get(tileChar);
			srcY = atoi(&tileChar) * TILE_DIM;
			
			stream.get(tileChar);
			srcX = atoi(&tileChar) * TILE_DIM;

			// add to the game
			Game::AddTile(srcX, srcY, x * (TILE_DIM * 2), y * (TILE_DIM * 2));

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