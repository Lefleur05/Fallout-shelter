#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Button.h"
#include"Zombie.h"
#include"GridNav.h"
#include "Canvas.h"
#include "TitleMenu.h"
#include "BuildMenu.h"
#include "TextWidget.h"
#include "ProgressBar.h"

using namespace sf;
using namespace std;

class Game
{
	Map* map;
	Canvas* canvas;
	TitleMenu* titleMenu;
	BuildMenu* buildMenu;

	TextWidget* capsuleCount;
	ProgressBar* electricityBar;


	Zombie* zombie;
	GridNav* grid;
public:
	Game();

public:
	void Init();
	void InitMap();
	void InitUIInfo();
	void InitButton();
	void InitGridNav();
	void InitTitleMenu();
	

	void Update();
	void UpdateUIInfo();
	void UpdateWindow();
};

