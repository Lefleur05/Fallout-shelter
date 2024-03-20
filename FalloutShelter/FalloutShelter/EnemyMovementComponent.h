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
public:
	EnemyMovementComponent(Actor* _owner);
	virtual void Init() override;
	virtual void Update(const float _deltaTime) override;
private:
	void Request();
	void MoveTo(const float _deltaTime);
};

