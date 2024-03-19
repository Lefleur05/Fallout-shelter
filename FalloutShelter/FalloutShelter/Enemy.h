#pragma once
#include"Entity.h"
#include"FSMEnemy.h"
#include"EnemyMovementComponent.h"

class Enemy : public Entity
{
protected:
	FSMEnemy* fsmEnemy = nullptr;
	EnemyMovementComponent* move = nullptr;
public:
	FSMEnemy* GetFSMEnemy()
	{
		return fsmEnemy;
	}
public:
	Enemy(const string& _name, const ShapeData& _data);
	virtual void Update(const float _deltaTime) override;
};

