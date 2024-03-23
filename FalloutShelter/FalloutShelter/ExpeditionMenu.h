#pragma once
#include "VillagerInfoMenu.h"
#include "VillagerInfoMenu.h"
class ExpeditionMenu
{
	VillagerInfoMenu* villagerInfoMenu;
	vector<Drawable*> backGround;

	ShapeObject* frameMenu;
	Canvas* canvas;

	Human* humanExpedition;

	bool closedBuildMEnu;

public:
	void SetBackGround(vector<Drawable*> _backGround)
	{
		backGround = _backGround;
	}

public:
	ExpeditionMenu();

public:
	void Init();
	void InitBackGround();
	void InitButtons();
	void InitHumanExpedition();


	void Update();
	void UpdateWindow();


};

