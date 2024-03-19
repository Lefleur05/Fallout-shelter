#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Map.h"

class MapManager : public Singleton<MapManager>, public IManager<string, Map>
{
public:
	vector<Drawable*> GetDrawables()
	{
		vector<Drawable*> _drawables;
		for (Map* _map: GetAllValues())
		{
			for (vector<Tile*> _tiles: _map->GetGrid()->GetAllTiles())
			{
				for (Tile* _tile : _tiles)
				{
					_drawables.push_back(_tile->GetShape());
				}
			}
		}
		return _drawables;
	}

public:
	void Update();

};

