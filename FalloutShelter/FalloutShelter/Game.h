#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"

using namespace sf;
using namespace std;

class Game
{
	Map* map;

public:
	Game();

public:
	void Init();
	void InitMap();
	
	void Update();
	void UpdateWindow();
};

