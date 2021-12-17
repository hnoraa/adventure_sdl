#pragma once

#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "global/defines.h"
#include <string>

class TileMap
{
public:
	TileMap();
	~TileMap();

	static void LoadMap(std::string mMapFile, int mSizeX, int mSizeY);
};

#endif // !TILE_MAP_H