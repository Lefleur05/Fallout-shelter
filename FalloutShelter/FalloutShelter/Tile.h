#pragma once
#include <SFML/Graphics.hpp>
#include "Hall.h"
#include "TextureManager.h"

using namespace sf;


#define DOOR_TEXTURE "Assets/Texture/Vault_door_T1.png"
#define DINER_TEXTURE "Assets/Texture/Diner_1_T1.png"
#define LIVING_QUARTER_TEXTURE "Assets/Texture/Living_quarter_1_T1.png"
#define POWER_GEN_TEXTURE "Assets/Texture/Power_gen_1_T1.png"
#define WATER_TREATMENT_TEXTURE "Assets/Texture/Water_treatment_1room_lvl1.png"
#define DIRT_TEXTURE "Assets/Texture/Dirt.png"


enum TileType
{
	ET_NONE,
};

class Tile
{
	TileType type;
	Shape* shape;
	Hall* hall;
	IntRect rect;

public:
	void SetHall(Hall* _hall)
	{
		hall = _hall;
		SetTexture();
	}
	void SetTexture()
	{
		shape->setFillColor(Color::White);
		switch (hall->GetType())
		{
		case HALL_DOOR:
			TextureManager::GetInstance().LoadWithRect(shape, DOOR_TEXTURE, rect);
			break;
		case HALL_ELEVATOR:
			break;
		case HALL_GENERATOR:
			TextureManager::GetInstance().LoadWithRect(shape, POWER_GEN_TEXTURE, rect);
			break;
		case HALL_FAST_FOOD:
			TextureManager::GetInstance().LoadWithRect(shape, DINER_TEXTURE, rect);
			break;
		case HALL_TRAITEMENT_DES_EAUX:
			TextureManager::GetInstance().LoadWithRect(shape, WATER_TREATMENT_TEXTURE, rect);
			break;
		case HALL_DORTOIR:
			TextureManager::GetInstance().LoadWithRect(shape, LIVING_QUARTER_TEXTURE, rect);
			break;
		default:
			break;
		}
	}


	Shape* GetShape()
	{
		return shape;
	}

public:
	Tile(const Vector2f& _position, const TileType& _type, const Vector2f& _size= Vector2f(100.0f,100.0f));
	~Tile();

public:
	

};

