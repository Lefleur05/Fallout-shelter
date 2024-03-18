#include "Map.h"

Map::Map()
{
	grid = new Grid(Vector2i(10, 10));
}

Map::~Map()
{
	delete grid;
}
