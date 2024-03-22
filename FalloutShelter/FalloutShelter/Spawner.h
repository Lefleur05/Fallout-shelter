#pragma once
#include"Enemy.h"
#include<SFML/Graphics.hpp>
#include<vector>
#include "Zombie.h"
using namespace sf;
class GridNav;

class Spawner : public Actor
{
	Timer* timeToWave;
	Zombie* enemySpawn;
	GridNav* grid;
	int number;
public:
	virtual void Init() override;
	Spawner(const string& _name,const ShapeData& _data, Zombie* _enemySpawn, GridNav* _grid);
	void SpawnWave();
};

