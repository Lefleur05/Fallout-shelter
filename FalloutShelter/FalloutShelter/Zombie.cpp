#include "Zombie.h"
#include"Actor.h"

Zombie::Zombie(const ShapeData& _data) : Enemy("Zombie", _data)
{
	fsmEnemy = new FSMEnemy(this);
}
