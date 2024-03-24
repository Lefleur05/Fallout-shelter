#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.h"
#include "ShapeObject.h"
#include "ScrollBar.h"
#include "TextWidget.h"
#include "Human.h"
#include "Button.h"
using namespace sf;
using namespace std;

struct VillagerInfo
{
	Button* villagerInfoShape;
	ShapeObject* villagerHead;
	vector<TextWidget*> villagerInfoText;
	Human* human;

public:
	Button* GetVillagerInfoShape()
	{
		return villagerInfoShape;
	}

	vector<TextWidget*> GetVillagerInfoText()
	{
		return villagerInfoText;
	}

	vector<Drawable*> GetDrawables()
	{
		vector<Drawable*> _drawables;
		_drawables.push_back(villagerInfoShape->GetDrawable());
		_drawables.push_back(villagerHead->GetDrawable());
		for (TextWidget* _text: villagerInfoText)
		{
			_drawables.push_back(_text->GetDrawable());
		}
		return _drawables;
	}

	void SetvillagerInfoText(vector<TextWidget*> _villagerInfoText)
	{
		villagerInfoText = _villagerInfoText;
	}

public:
	VillagerInfo(Human* _human);
	
public:
	void Init();
	void InitStats();
	void InitVillagerHead();
	void CreateTextStat(const string& _text, const float& _positionX);
	void SetPositionY(const float& _positionY);
};


struct VillagerList
{
	vector<VillagerInfo*> villagerList;

public:
	vector<VillagerInfo*> GetVillagerList()
	{
		return villagerList;
	}

	void SetVillagerList(vector<VillagerInfo*> _villagerList)
	{
		villagerList = _villagerList;
	}


public:
	VillagerList();

public:
	void Init();
	void Set3VillagerInfoPosition(const int& _scrole);
	void UpdateVillagerList();
};


class VillagerInfoMenu
{
	ScrollBar* handle;
	vector<Drawable*> backGround;
	VillagerList* villagerInfo;
	ShapeObject* frameMenu;
	ShapeObject* frameStatName;
	Canvas* canvas;

	Human* currentHuman;

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
	void InitStatsName();
	void InitButtons();
	void InitScrollBar();

	void ComputeScroll(VillagerList* _data, const bool _scrollType);

	Human* Update();
	void UpdateInit();
	void UpdateWindow();
};

