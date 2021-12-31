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
			srcY = atoi(&tileChar) * 32;
			
			stream.get(tileChar);
			srcX = atoi(&tileChar) * 32;

			// add to the game
			Game::AddTile(srcX, srcY, x * (32 * 2), y * (32 * 2));

			// ignore the comma
			stream.ignore();
		}
	}

	stream.close();
}