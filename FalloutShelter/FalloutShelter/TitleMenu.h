#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.h"

using namespace sf;
using namespace std;

class TitleMenu
{
	Shape* backGround;
	Canvas* canvas;

	bool launchGame;

public:
	TitleMenu();
	~TitleMenu();

public:
	void Init();
	void InitBackGround();
	void InitButton();

	void Update();
	void UpdateWindow();








};

