#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Button.h"
#include"Zombie.h"

using namespace sf;
using namespace std;

class Game
{
	Map* map;

	Zombie* zombie;

public:
	Game();
	~Game();

public:
	void Init();
	void InitMap();
	void InitButton();
	void TestEntity();


	void Update();
	void UpdateWindow();
};

