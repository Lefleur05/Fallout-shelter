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
		SetTexture();
	}
	void SetTexture()
	{
		switch (hall->GetType())
		{
		case HALL_DOOR:
			break;
		case HALL_ELEVATOR:
			break;
		case HALL_GENERATOR:
			break;
		case HALL_FAST_FOOD:
			break;
		case HALL_TRAITEMENT_DES_EAUX:
			break;
		case HALL_DORTOIR:
			break;
		default:
			break;
		}
	}

public:
	Tile(const Vector2f& _position, const TileType& _type, const Vector2f& _size= Vector2f(100.0f,100.0f));
	~Tile();

public:
	

};

