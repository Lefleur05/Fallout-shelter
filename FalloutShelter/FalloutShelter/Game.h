#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Button.h"
#include"Zombie.h"
#include"GridNav.h"

using namespace sf;
using namespace std;

class Game
{
	Map* map;

	Zombie* zombie;
	GridNav* grid;
public:
	Game();
	~Game();

public:
	void Init();
	void InitMap();
	void InitButton();
	void InitGridNav();

	void Update();
	void UpdateWindow();
};

