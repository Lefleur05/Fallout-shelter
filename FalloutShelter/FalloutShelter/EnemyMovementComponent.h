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
	Timer* timeRequestPath;

public:
	virtual void Init() override;
	void FollowPath(const float _deltaTime);
	EnemyMovementComponent(Actor* _owner);
	void SetGrid(GridNav* _grid)
	{
		grid = _grid;
	}
private:
	void Request();
};

