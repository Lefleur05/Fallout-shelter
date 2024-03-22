#include "Zombie.h"
#include"Actor.h"
#include"TextureManager.h"
#include"Macro.h"
#include <iostream>
#include "DevUtils.h"


Zombie::Zombie(const ShapeData& _data) : Enemy(STRING_ID("Zombie"), _data)
{
	fsmEnemy = new FSMEnemy(this);
	components.push_back(fsmEnemy);
	attack = new AttackComponent(this, 2);
	components.push_back(attack);
}

void Zombie::Init()
{
	Entity::Init();
}
