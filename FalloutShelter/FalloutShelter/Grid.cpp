#include "Grid.h"
#include "GameWindow.h"

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
	Vector2f _tileSize = Vector2f(WINDOW_SIZE.x/ tilesCount.x, WINDOW_SIZE.y / tilesCount.y);

	for (int _y = 0; _y < tilesCount.x; _y++)
	{
		vector<Tile*> _tiles;
		for (int _x = 0; _x < tilesCount.y; _x++)
		{
			if (_x==0 && _y ==0)
			{
				Tile* tile = new Tile(Vector2f(_x * WINDOW_SIZE.x / tilesCount.x, _y * WINDOW_SIZE.y / tilesCount.y+100.0f), ET_EXTERNE, _tileSize);
				_tiles.push_back(tile);
				continue;
			}
			Tile* tile = new Tile(Vector2f(_x* WINDOW_SIZE.x / tilesCount.x , _y * WINDOW_SIZE.y / tilesCount.y+100.0f),ET_BUILDABLE, _tileSize);
			_tiles.push_back(tile);
		}
		allTiles.push_back(_tiles);
	}


}
