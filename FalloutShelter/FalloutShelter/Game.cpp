#include "Game.h"
#include "MapManager.h"
#include "GameWindow.h"
#include"Spawner.h"
#include"ActorManager.h"
#include"Macro.h"

Game::Game()
{
	map = nullptr;
	buttons = vector<Button*>();
	Init();
}

Game::~Game()
{
	for (Button* _button: buttons)
	{
		delete _button;
	}
}

void Game::Init()
{
	InitMap();
	TestEntity();
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


}

void Game::TestEntity()
{
	Vector2f _position = Vector2f(10,10);
	Vector2f _size = Vector2f(30, 30);
	Spawner* _spawner = new Spawner(zombie, _position, _size, 6);
}

void Game::Update()
{
	while (WINDOW->isOpen())
	{
		Event _event;
		while (WINDOW->pollEvent(_event))
		{
			if (_event.type == Event::Closed)WINDOW->close();
		}

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
	for (Drawable* _drawables : ActorManager::GetInstance().GetDrawables())
	{
		WINDOW->draw(*_drawables);
	}
	WINDOW->display();

}
