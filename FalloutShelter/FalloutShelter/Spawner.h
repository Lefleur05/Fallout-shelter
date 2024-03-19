#pragma once
#include"Entity.h"
#include<SFML/Graphics.hpp>
#include<vector>

using namespace sf;
class Spawner
{
	Vector2f location;
public:
	Spawner(Entity* _entitySpawn, Vector2f _location,Vector2f _size, int _numberEntity = 1);
	~Spawner();
private:
	 void Spawn(Entity* _entitySpawn, Vector2f _location,Vector2f _size,int _numberEntity = 1);
};

