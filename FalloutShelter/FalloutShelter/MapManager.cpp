#include "MapManager.h"

void MapManager::Update()
{
	for (vector<Tile*> _tiles: GetCurrent()->GetGrid()->GetAllTiles())
	{
		for (Tile* _tile: _tiles)
		{
			_tile->Update();
		}
	}
	
}
