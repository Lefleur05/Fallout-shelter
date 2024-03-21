#pragma once
#include "Human.h"
#include "Timer.h"
#include "Canvas.h"
#include<vector>
#include<iostream>
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
	int quantity;
	
	Canvas* canvas;
	Timer* timerRessource;


public:
	HallType GetType() 
	{
		return type;
	}

	Timer* GetTimer()
	{
		return timerRessource;
	}

	Canvas* GetCanvas()
	{
		return canvas;
	}

public:
	Hall(HallType _type);

public:
	void Init(Shape* _shape, Vector2f _size);
	void InitQuantity();
	void InitTimer();
	void InitButton(Shape* _shape, Vector2f _size);

	void DrawButton();
	void AddRessourceType();
	void AddHumanInHall(Human* _human);



};

