#pragma once
#include <SFML/Graphics.hpp>
#include "Hall.h"
#include "TextureManager.h"

using namespace sf;


#define EXTRENE_TEXTURE "Assets/Texture/Externe.png"
#define DOOR_TEXTURE "Assets/Texture/Vault_door_T1.png"
#define ELEVATOR_TEXTURE "Assets/Texture/Elevator.png"
#define DINER_TEXTURE "Assets/Texture/Diner_1_T1.png"
#define LIVING_QUARTER_TEXTURE "Assets/Texture/Living_quarter_1_T1.png"
#define POWER_GEN_TEXTURE "Assets/Texture/Power_gen_1_T1.png"
#define WATER_TREATMENT_TEXTURE "Assets/Texture/Water_treatment_1room_lvl1.png"
#define DIRT_TEXTURE "Assets/Texture/Dirt.png"


enum TileType
{
	ET_BUILDABLE,
	ET_BUILD,
	ET_EXTERNE,
};

class Tile
{
	TileType type;
	Shape* shape;
	Vector2f size;
	Hall* hall;

public:
	void SetHall(Hall* _hall)
	{
		hall = _hall;
		hall->Init(shape, size);
		SetTexture();
	}
	void SetTexture()
	{
		if (type== ET_EXTERNE)
		{
			return;
		}

		type = ET_BUILD;
		shape->setFillColor(Color::White);

		switch (hall->GetType())
		{

		case HALL_DOOR:
			TextureManager::GetInstance().Load(shape, DOOR_TEXTURE);
			break;
		case HALL_ELEVATOR:
			TextureManager::GetInstance().Load(shape, ELEVATOR_TEXTURE);
			break;
		case HALL_GENERATOR:
			TextureManager::GetInstance().Load(shape, POWER_GEN_TEXTURE);
			break;
		case HALL_FAST_FOOD:
			TextureManager::GetInstance().Load(shape, DINER_TEXTURE);
			break;
		case HALL_TRAITEMENT_DES_EAUX:
			TextureManager::GetInstance().Load(shape, WATER_TREATMENT_TEXTURE);
			break;
		case HALL_DORTOIR:
			TextureManager::GetInstance().Load(shape, LIVING_QUARTER_TEXTURE);
			break;
		default:
			break;
		}
	}

	Shape* GetShape()
	{
		return shape;
	}
	Hall* GetHall()
	{
		return hall;
	}

public:
	Tile(const Vector2f& _position, const TileType& _type= ET_BUILDABLE, const Vector2f& _size= Vector2f(100.0f,100.0f));
	~Tile();
};

