#pragma once
#include "Grid.h"

class Map
{
	Grid* grid;

public:
	Grid* GetGrid() 
	{ 
		return grid;
	}

public:
	Map();
	~Map();

};

