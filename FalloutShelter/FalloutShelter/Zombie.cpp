#include "Zombie.h"
#include"Actor.h"
#include"TextureManager.h"
#include <iostream>



Zombie::Zombie(const ShapeData& _data) : Enemy("Zombie", _data)
{
	fsmEnemy = new FSMEnemy(this);
	components.push_back(fsmEnemy);
	attack = new AttackComponent(this, 2);
	components.push_back(attack);
	pathZombie = "Characters/Zombie.png";
	TextureManager::GetInstance().Load(shape, pathZombie);
}
