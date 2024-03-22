#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.h"
#include "ShapeObject.h"
#include "ScrollBar.h"
#include "TextWidget.h"
#include "Human.h"
using namespace sf;
using namespace std;

struct VillagerInfo
{
	ShapeObject* villagerInfoShape;
	ShapeObject* villagerHead;
	vector<TextWidget*> villagerInfoText;

public:
	ShapeObject* GetVillagerInfoShape()
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

public:
	VillagerInfo(Human* _human);
	
public:
	void Init(Human* _human);
	void InitStats(Human* _human);
	void InitMentalHealth(Human* _human);
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

	void Update();
	void UpdateWindow();
};

