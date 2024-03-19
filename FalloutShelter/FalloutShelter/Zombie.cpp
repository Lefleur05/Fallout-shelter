#include "Zombie.h"
#include"Actor.h"
#include"TextureManager.h"
#include <iostream>



Zombie::Zombie(const ShapeData& _data) : Enemy("Zombie", _data)
{
	fsmEnemy = new FSMEnemy(this);
	components.push_back(fsmEnemy);
	pathZombie = "Characters/Zombie.png";
	TextureManager::GetInstance().Load(shape, pathZombie);
}
