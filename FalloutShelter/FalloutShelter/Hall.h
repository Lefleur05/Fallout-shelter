#pragma once
#include "Human.h"
#include<vector>
using namespace std;

enum HallType
{
	HALL_DOOR,
	HALL_ELEVATOR,
	HALL_GENERATOR,
	HALL_FAST_FOOD,
	HALL_TRAITEMENT_DES_EAUX,
	HALL_DORTOIR
};

class Hall
{
	HallType type;
	int hallSize;
	int hallLV;
	vector<Human*> humans;

public:
	HallType GetType() 
	{
		return type;
	}

public:
	Hall(HallType _type);


};

