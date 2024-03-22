#include "Zombie.h"
#include"Actor.h"
#include"TextureManager.h"
#include"Macro.h"
#include <iostream>
#include "DevUtils.h"
#include"GridNav.h"

#define ZOMBIE_PATH "Characters/Zombie.png"

Zombie::Zombie(const ShapeData& _data) : Enemy(STRING_ID("Zombie"), ShapeData(_data.position, _data.size, ZOMBIE_PATH, _data.rect))
{
	fsmEnemy = new FSMEnemy(this);
	components.push_back(fsmEnemy);
	attack = new AttackComponent(this, 2);
	components.push_back(attack);
}

void Zombie::OnDestroy()
{
	Destroy();
	move->GetTimeRequestPath()->Stop();
}

void Zombie::Init()
{
	Entity::Init();
	timerToDestroy = new Timer([&]() {OnDestroy(); }, seconds(10), true, false);
}
