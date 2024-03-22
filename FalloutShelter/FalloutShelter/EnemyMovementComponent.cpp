#include "EnemyMovementComponent.h"
#include"Actor.h"
#include"Macro.h"
#include"GridNav.h"
#include"MapManager.h"
#include "DevUtils.h"


EnemyMovementComponent::EnemyMovementComponent(Actor* _owner) : MovementComponent(_owner)
{
	minRange = 0.5f;
	delaisPath = 1.f;
	astar = new AstarAlgo();
	canMove = true;
	timeRequestPath = nullptr;
}

void EnemyMovementComponent::Request()
{
	if (!astar || !grid)
		return;
	index = 0;
	astar->ComputePath(grid->GetClosesNode(owner->GetShapePosition()), grid->GetClosesNode(grid->GetNodes()[80]->GetShapePosition()));
	grid->GetNodes()[80]->GetShape()->setFillColor(Color::Cyan);
}

void EnemyMovementComponent::Init()
{
	timeRequestPath = new Timer([&]() {Request(); }, seconds(1), true, true);
}

void EnemyMovementComponent::FollowPath(const float _deltaTime)
{
	if (astar->GetPathList().size() == 0)
	{
		return;
	}
	const int& _max = astar->GetPathList().size() - 1; 
	if (IsAtPosition() && index <_max)
	{
		index++;
	}
	SetDestination(astar->GetPathList()[index]->GetShapePosition());
}




