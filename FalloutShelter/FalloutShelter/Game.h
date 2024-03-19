#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include"Zombie.h"
//#include"Entity.h"

using namespace sf;
using namespace std;

class Game
{
	RenderWindow* window;
	Vector2f windowSize;

	Map* map;

	Zombie* zombie;

public:
	Game();

public:
	void Init();
	void InitMap();

	void InitEntity();
	
	void Update();
	void UpdateWindow();
};

