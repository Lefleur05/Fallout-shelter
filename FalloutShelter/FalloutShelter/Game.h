#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Button.h"
#include"Zombie.h"
#include"Human.h"
#include"GridNav.h"
#include "Canvas.h"
#include "TitleMenu.h"
#include "Bunker.h"
#include "BuildMenu.h"

using namespace sf;
using namespace std;

class Game
{
	Bunker* playerBunker;
	Map* map;
	Canvas* canvas;
	TitleMenu* titleMenu;
	BuildMenu* buildMenu;

	Zombie* zombie;
	GridNav* grid;

	vector<Human*> allHuman;

public:
	Game();

public:
	void Init();
	void InitHuman();
	void InitBunkerPlayer();
	void InitMap();
	void InitUIInfo();
	void InitButton();
	void InitGridNav();
	void InitTitleMenu();

	void InitZombie();
	
	void DrawActor();
	void DrawMap();

	void DrawHuman();

	void Update();
	void UpdateWindow();

	Vector2f PositionHumanInHall(int _indexX, int _indexY, Vector2f _offset);
};

