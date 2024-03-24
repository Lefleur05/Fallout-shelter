#pragma once
#include "VillagerInfoMenu.h"
#include "VillagerInfoMenu.h"
class ExpeditionMenu
{
	VillagerInfoMenu* villagerInfoMenu;
	vector<Drawable*> backGround;

	ShapeObject* frameMenu;
	ShapeObject* frameBackgroundItem;
	ShapeObject* frameBackgroundEvent;
	ShapeObject* humanDraw;
	TextWidget* capsuleCount;
	int capsuleCountint;
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
	void InitCloseButton();
	void InitItemsButton();
	void InitEventButton();
	void InitframeMenu();
	void InitframeBackgroundItem();
	void IniframeBackgroundEvent();
	void InitRessource();

	void HumanExpedition();

	void Update();
	void UpdateWindow();


};

