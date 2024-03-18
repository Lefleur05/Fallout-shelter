#pragma once
#include <SFML/Graphics.hpp>
#include "Hall.h"

using namespace sf;

enum TileType
{
	ET_NONE,
};

class Tile
{
	TileType type;
	Shape* shape;
	Hall* hall;

public:
	void SetHall(Hall* _hall)
	{
		hall = _hall;
	}

public:
	Tile(const Vector2f& _position, const TileType& _type, const Vector2f& _size= Vector2f(100.0f,100.0f));
	~Tile();

};

