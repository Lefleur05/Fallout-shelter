#include "Map.h"
#include "Macro.h"
#include "MapManager.h"

Map::Map(const string& _name) : IManagable(_name+to_string(GetUniqueID()))
{
	grid = new Grid(Vector2i(10, 10));
	Register();
}

Map::~Map()
{
	delete grid;
}

void Map::Register()
{
	MapManager::GetInstance().Add(id, this);
}
