#pragma once

#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "global/defines.h"
#include <string>

class TileMap
{
public:
	TileMap(const char *mMapFilePath, int mMapScale, int mTileSize);
	~TileMap();

	void LoadMap(std::string mMapFile, int mSizeX, int mSizeY);
	void AddTile(int mSrcX, int mSrcY, int mXPos, int mYPos);
	void AddCollider(std::string mTag, int mXPos, int mYPos, int scale);
private:
	const char* _mapFilePath;
	int _mapScale;
	int _tileSize;
	int _scaleFactor;
};

#endif // !TILE_MAP_H
