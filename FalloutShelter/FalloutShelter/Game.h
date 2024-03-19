#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Button.h"

using namespace sf;
using namespace std;

class Game
{
	Map* map;
	vector< Button*> buttons;

public:
	Game();
	~Game();

public:
	void Init();
	void InitMap();
	void InitButton();
	
	void Update();
	void UpdateWindow();
};

