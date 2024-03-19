#include "Game.h"
#include "MapManager.h"
#include"ActorManager.h"
#include"Spawner.h"

Game::Game()
{
	windowSize = Vector2f(1200.0f, 800.0f);
	window = new RenderWindow();
	window->create(VideoMode(1200, 800), "Fallout Shelter");
	map = nullptr;
	Init();
}

void Game::Init()
{
	InitMap();
	InitEntity();
}

void Game::InitMap()
{
	map = new Map("map");
	map->GetGrid()->GetAllTiles()[0][0]->SetHall(new Hall(HALL_DOOR));
	map->GetGrid()->GetAllTiles()[0][1]->SetHall(new Hall(HALL_DORTOIR));
	map->GetGrid()->GetAllTiles()[0][2]->SetHall(new Hall(HALL_ELEVATOR));
	map->GetGrid()->GetAllTiles()[1][2]->SetHall(new Hall(HALL_ELEVATOR));
	map->GetGrid()->GetAllTiles()[1][1]->SetHall(new Hall(HALL_GENERATOR));
	map->GetGrid()->GetAllTiles()[1][0]->SetHall(new Hall(HALL_FAST_FOOD));
	map->GetGrid()->GetAllTiles()[1][3]->SetHall(new Hall(HALL_TRAITEMENT_DES_EAUX));
}

void Game::InitEntity()
{
	Vector2f _position = Vector2f(20, 20);
	Vector2f _size = Vector2f(10, 10);
	ShapeData _shape = ShapeData(_position,_size);
	Spawner* _spawn = new Spawner(zombie, _position, _size);
}

void Game::Update()
{
	while (window->isOpen())
	{
		Event _event;
		while (window->pollEvent(_event))
		{
			if (_event.type == Event::Closed)window->close();
		}
		ActorManager::GetInstance().Update();
		UpdateWindow();
	}
}

void Game::UpdateWindow()
{
	window->clear();

	for (Drawable* _drawables: MapManager::GetInstance().GetDrawables())
	{
		window->draw(*_drawables);
	}
	window->display();

}
