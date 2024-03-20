#pragma once
#include"Entity.h"
#include"FSMEnemy.h"
#include"EnemyMovementComponent.h"
#include"AttackComponent.h"

class Enemy : public Entity
{
protected:
	FSMEnemy* fsmEnemy = nullptr;
	EnemyMovementComponent* move = nullptr;
	AttackComponent* attack = nullptr;
public:
	FSMEnemy* GetFSMEnemy()
	{
		return fsmEnemy;
	}
public:
	Enemy(const string& _name, const ShapeData& _data);
	virtual void Update(const float _deltaTime) override;
};

