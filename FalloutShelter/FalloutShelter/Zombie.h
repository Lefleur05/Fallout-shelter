#pragma once
#include"Enemy.h"
class Zombie : public Enemy
{
	string pathZombie;
public:
	Zombie(const ShapeData& _data);
};

