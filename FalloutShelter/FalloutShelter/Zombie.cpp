#include "Zombie.h"
#include"Actor.h"
#include <iostream>



Zombie::Zombie(const ShapeData& _data) : Enemy("Zombie", _data)
{
	fsmEnemy = new FSMEnemy(this);
	components.push_back(fsmEnemy);
	pathZombie = _data.path;
}
