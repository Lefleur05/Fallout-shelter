#pragma once
#include"Enemy.h"
class Zombie : public Enemy
{
	Timer* timerToDestroy;
public:
	virtual void Init() override; 
	//virtual void Update(const float _delta) override;
	Zombie(const ShapeData& _data);
	void OnDestroy();
};

