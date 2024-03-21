#pragma once
#include"MovementComponent.h"
#include"AstarAlgo.h"

class EnemyMovementComponent : public MovementComponent
{
	AstarAlgo* astar;
	GridPointData* data;
	Vector2f destination;
	bool canMove;
	float minRange;
	int index = 0;
public:
	EnemyMovementComponent(Actor* _owner);
	virtual void Init() override;
	virtual void Update(const float _deltaTime) override;
	void Request(Vector2f _target);
private:
	void MoveTo(const float _deltaTime);
};

