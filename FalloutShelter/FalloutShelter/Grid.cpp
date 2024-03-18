#include "Grid.h"

Grid::Grid(Vector2i _tilesCount)
{
	tilesCount = _tilesCount;
	allTiles = vector<vector<Tile*>>();
	InitTiles();
}

Grid::~Grid()
{
	for (int _x = 0; _x < tilesCount.x; _x++)
	{
		for (int _y = 0; _y < tilesCount.y; _y++)
		{
			delete allTiles[_x][_y];
		}
	}
}

void Grid::InitTiles()
{

	for (int _x = 0; _x < tilesCount.x; _x++)
	{
		vector<Tile*> _tiles;
		for (int _y = 0; _y < tilesCount.y; _y++)
		{
			Tile* tile = new Tile(Vector2f(_x, _y),ET_NONE);
			_tiles.push_back(tile);
		}
		allTiles.push_back(_tiles);
	}


}
