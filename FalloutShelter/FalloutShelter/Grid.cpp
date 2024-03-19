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
	Vector2f _tileSize = Vector2f(200.0f, 100.0f);

	for (int _y = 0; _y < tilesCount.x; _y++)
	{
		vector<Tile*> _tiles;
		for (int _x = 0; _x < tilesCount.y; _x++)
		{
			Tile* tile = new Tile(Vector2f(_x* _tileSize.x, _y * _tileSize.y),ET_NONE, _tileSize);
			_tiles.push_back(tile);
		}
		allTiles.push_back(_tiles);
	}


}
