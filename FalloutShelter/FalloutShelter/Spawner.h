#pragma once
#include"Entity.h"
#include<SFML/Graphics.hpp>
using namespace sf;
class Spawner
{
public:
	Spawner(Entity* _entitySpawn, Vector2f _location, Vector2f _size, int _numberEntity = 1);
	~Spawner();
private:
	void Spawn(Entity* _entitySpawn,Vector2f _location,Vector2f _size,int _numberEntity = 1);
};

