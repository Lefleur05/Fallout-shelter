#pragma once
#include"Actor.h"
#include"FSMEnemy.h"

class Enemy : public Actor //hérite de Entity
{
protected:
	FSMEnemy* fsmEnemy = nullptr;
public:
	FSMEnemy* GetFSMEnemy()
	{
		return fsmEnemy;
	}
public:
	Enemy(const string& _name, const ShapeData& _data);
	virtual void Update(const float _deltaTime) override;
};

