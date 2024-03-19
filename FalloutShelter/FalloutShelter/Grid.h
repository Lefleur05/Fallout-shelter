#pragma once
#include<vector>
#include"Tile.h"
using namespace std;


class Grid
{
	Vector2i tilesCount;
	vector<vector<Tile*>> allTiles;

public:
	vector<vector<Tile*>> GetAllTiles() 
	{
		return allTiles; 
	}

public:
	Grid(Vector2i _tilesCount);
	~Grid();

public:
	void InitTiles();


};

