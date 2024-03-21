#pragma once
#include"MovementComponent.h"
#include"AstarAlgo.h"

class EnemyMovementComponent : public MovementComponent
{
	AstarAlgo* astar;
	GridNav* grid;
	bool canMove;
	float minRange;
	float delaisPath;
	int index = 0;
	Timer* requestTimer;
	Timer* moveTimer;
public:
	virtual void Init() override;
	EnemyMovementComponent(Actor* _owner);
	void TimerMove();
	void Request();
	void ChangePoint();
	void SetGrid(GridNav* _grid)
	{
		grid = _grid;
	}
};

