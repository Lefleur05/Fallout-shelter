#include "Game.h"
#include "MapManager.h"
#include "GameWindow.h"
#include "HUD.h"
#include "InputManager.h"

Game::Game()
{
	map = nullptr;
	Init();
}

Game::~Game()
{

}

void Game::Init()
{
	InitMap();
	InitButton();
}

void Game::InitMap()
{
	map = new Map("map");
	map->GetGrid()->GetAllTiles()[0][2]->SetHall(new Hall(HALL_ELEVATOR));
	map->GetGrid()->GetAllTiles()[0][3]->SetHall(new Hall(HALL_DORTOIR));
	map->GetGrid()->GetAllTiles()[1][2]->SetHall(new Hall(HALL_ELEVATOR));
	map->GetGrid()->GetAllTiles()[1][1]->SetHall(new Hall(HALL_GENERATOR));
	map->GetGrid()->GetAllTiles()[1][0]->SetHall(new Hall(HALL_FAST_FOOD));
	map->GetGrid()->GetAllTiles()[1][3]->SetHall(new Hall(HALL_TRAITEMENT_DES_EAUX));
}

void Game::InitButton()
{
	Canvas* _canvas = new Canvas("Button");

	Button* _modeBuildButton = new Button(ShapeData(Vector2f(1000,700), Vector2f(100.0f, 100.0f)), ButtonData());
	Button* _modeExplorationButton = new Button(ShapeData(Vector2f(100, 100), Vector2f(100.0f, 100.0f)), ButtonData());
	Button* _villagerInfoButton = new Button(ShapeData(Vector2f(100, 700), Vector2f(100.0f, 100.0f)), ButtonData());

	_modeBuildButton->GetData().releasedCallback = [&]()
	{
		cout << "mode build" << endl;
	};

	_modeExplorationButton->GetData().releasedCallback = [&]()
	{
		cout << "mode Exploration" << endl;
	};

	_villagerInfoButton->GetData().releasedCallback = [&]()
	{
		cout << "villager Info" << endl;
	};

	_canvas->AddWidget(_modeBuildButton);
	_canvas->AddWidget(_modeExplorationButton);
	_canvas->AddWidget(_villagerInfoButton);
}

void Game::Update()
{
	while (WINDOW->isOpen())
	{
		if (!InputManager::GetInstance().Update(*WINDOW)) break;


		UpdateWindow();
	}
}

void Game::UpdateWindow()
{

	WINDOW->clear();

	for (Drawable* _drawables: MapManager::GetInstance().GetDrawables())
	{
		WINDOW->draw(*_drawables);
	}

	for (Canvas* _canvas : HUD::GetInstance().GetAllValues())
	{
		for (Widget* _widget : _canvas->GetUiWidgets())
		{
			WINDOW->draw(*_widget->GetDrawable());

		}
	}

	WINDOW->display();

}
