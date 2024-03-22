#include "Spawner.h"
#include"ActorManager.h"
#include <iostream>
#include"Macro.h"
#include"GridNav.h"


void Spawner::Init()
{
	timeToWave = new Timer([&]() {SpawnWave(); }, seconds(10), true, true);
}

Spawner::Spawner(const string& _name, const ShapeData& _data, Zombie* _enemySpawn, GridNav* _grid) : Actor(STRING_ID(_name), _data)
{
	enemySpawn = _enemySpawn;
	grid = _grid;
}

void Spawner::SpawnWave()
{
	enemySpawn = new Zombie(ShapeData(grid->GetNodes()[99]->GetShapePosition(), Vector2f(20, 60)));
	enemySpawn->GetComponent<EnemyMovementComponent>()->SetGrid(grid);
	enemySpawn->GetShape()->setFillColor(Color::Blue);
	enemySpawn->Init();
}



