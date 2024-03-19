#pragma once
#include "Grid.h"
#include "IManagable.h"

class Map : public IManagable<string>
{
	Grid* grid;

public:
	Grid* GetGrid() 
	{ 
		return grid;
	}

public:
	Map(const string& _name);
	~Map();


public:
	void Register();

};

