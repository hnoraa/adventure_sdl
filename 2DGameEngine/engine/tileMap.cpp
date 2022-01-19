#include "tileMap.h"
#include "textureManager.h"
#include "game.h"
#include "ECS/ECS.h"
#include "ECS/components.h"
#include <fstream>

extern Manager manager;	// this is externally defined in the game class

TileMap::TileMap(std::string mTextureId, int mMapScale, int mTileSize) : _textureId(mTextureId), _mapScale(mMapScale), _tileSize(mTileSize)
{
	_scaleFactor = (_tileSize * _mapScale);
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

	// get the tile layer
	for (int y = 0; y < mSizeY; y++) 
	{
		for (int x = 0; x < mSizeX; x++) 
		{
			// tile comes in as two digits (ex: 00)
			// first digit is Y
			// second is X
			stream.get(tileChar);
			srcY = atoi(&tileChar) * _tileSize;
			
			stream.get(tileChar);
			srcX = atoi(&tileChar) * _tileSize;

			// add to the game
			AddTile(srcX, srcY, x * _scaleFactor, y * _scaleFactor);

			// ignore the comma (skip)
			stream.ignore();
		}
	}

	// ignore the new line between tile layer and collider layer
	stream.ignore();

	// terrain colliders
	for (int y = 0; y < mSizeY; y++)
	{
		for (int x = 0; x < mSizeX; x++)
		{
			stream.get(tileChar);
			if (tileChar == '1')
			{
				// this is a terrain tile, add to the game
				AddCollider("terrain", x * _scaleFactor, y * _scaleFactor, _scaleFactor);
			}

			// ignore the comma (skip)
			stream.ignore();
		}
	}

	stream.close();
}

void TileMap::AddTile(int mSrcX, int mSrcY, int mXPos, int mYPos)
{
	auto& tile(manager.AddEntity());
	tile.AddComponent<TileComponent>(mSrcX, mSrcY, mXPos, mYPos, _tileSize, _mapScale, _textureId);
	tile.AddGroup(Game::G_MAP);
}

void TileMap::AddCollider(std::string mTag, int mXPos, int mYPos, int scale)
{
	auto& tCollider(manager.AddEntity());
	tCollider.AddComponent<ColliderComponent>(mTag, mXPos, mYPos, scale);
	tCollider.AddGroup(Game::G_COLLIDERS);
}