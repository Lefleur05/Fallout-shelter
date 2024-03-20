#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Button.h"
#include"Zombie.h"
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
public:
	Game();

public:
	void Init();
	void InitBunkerPlayer();
	void InitMap();
	void InitUIInfo();
	void InitButton();
	void InitGridNav();
	void InitTitleMenu();
	

	void Update();
	void UpdateWindow();
};

