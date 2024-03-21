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
	vector<Tile*> GetRessourceTiles()
	{
		vector<Tile*> _ressourceTiles;

		for (vector<Tile*> _tiles: allTiles)
		{
			for (Tile* _tile: _tiles)
			{
				if (_tile->GetHall() == nullptr)continue;
				switch (_tile->GetHall()->GetType())
				{
				case HALL_GENERATOR:
					_ressourceTiles.push_back(_tile);
					break;
				case HALL_FAST_FOOD:
					_ressourceTiles.push_back(_tile);
					break;
				case HALL_TRAITEMENT_DES_EAUX:
					_ressourceTiles.push_back(_tile);
					break;
				case HALL_DORTOIR:
					_ressourceTiles.push_back(_tile);
					break;
				default:
					break;
				}
			}
		}
		return _ressourceTiles;
	}


public:
	Grid(Vector2i _tilesCount);
	~Grid();

public:
	void InitTiles();


};

