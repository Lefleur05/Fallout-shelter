#include "Spawner.h"
#include"ActorManager.h"
#include <iostream>
#include"Macro.h"

Spawner::Spawner(Entity* _entitySpawn, Vector2f _location,Vector2f _size, int _numberEntity)
{
	Spawn(_entitySpawn,_location,_size, _numberEntity);
}

Spawner::~Spawner()
{

}

void Spawner::Spawn(Entity* _entitySpawn,Vector2f _location,Vector2f _size, int _numberEntity)
{
	for (size_t i = 0; i < _numberEntity; i++)
	{
		ShapeData _shapeData = ShapeData(_location, _size);
		_entitySpawn = new Entity("Entity", _shapeData);
		_entitySpawn->Init();
	}
}

