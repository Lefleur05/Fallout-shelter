#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.h"
#include "ShapeObject.h"

using namespace sf;
using namespace std;

class VillagerInfoMenu
{
	vector<Drawable*> backGround;
	vector<ShapeObject*> villagerList;
	ShapeObject* frameMenu;
	Canvas* canvas;

	bool closedBuildMEnu;

	int scrole;

public: 
	
	void SetBackGround(vector<Drawable*> _backGround)
	{
		backGround = _backGround;
	}

public:
	VillagerInfoMenu();
	~VillagerInfoMenu();

public:
	void Init();
	void InitBackGround();
	void InitVillagerList();
	void InitButtons();

	void Update();
	void UpdateWindow();
};

