//#include "Game.h"
#include "Map.h"
#include "Hall.h"
#include "Man.h"
#include<iostream>

using namespace std;


int main()
{
	/*locale::global(locale(""));
	srand(static_cast<unsigned>(time(nullptr)));
    Game _game;
    _game.Launch();*/




	/*Map* _map = new Map();
	cout << _map->GetGrid()->GetAllTiles().size() << endl;

	_map->GetGrid()->GetAllTiles()[0][0]->SetHall(new Hall(HALL_DOOR));
	cout << _map->GetGrid()->GetAllTiles()[0][0] << endl;*/


	Man* _man = new Man(Vector2f(10.0f,10.0f));
	



	return 0;
}
