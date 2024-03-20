#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.h"
#include "ShapeObject.h"

using namespace sf;
using namespace std;

class BuildMenu
{
	vector<Drawable*> backGround;
	ShapeObject* frameMenu;
	Canvas* canvas;
	bool closedBuildMEnu;

public:
	void SetBackGround(vector<Drawable*> _backGround)
	{
		backGround = _backGround;
	}

public:
	BuildMenu();

public:
	void Init();
	void Update();
	void UpdateWindow();

	void InitBackGround();
	void InitButtons();

};

