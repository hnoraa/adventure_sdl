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