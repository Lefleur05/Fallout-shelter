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
	bool canAttack = false;
public:
	virtual void Init() override;
	void FollowPath(const float _deltaTime);
	EnemyMovementComponent(Actor* _owner);
	~EnemyMovementComponent();
	void SetGrid(GridNav* _grid)
	{
		grid = _grid;
	}
	Timer* GetTimeRequestPath()
	{
		return timeRequestPath;
	}	
	bool GetCanAttack()
	{
		return canAttack;
	}
private:
	bool IsAtLocation();
	void Request();
};

