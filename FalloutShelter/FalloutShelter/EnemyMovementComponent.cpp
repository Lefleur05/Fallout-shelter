#include "EnemyMovementComponent.h"
#include"Actor.h"
#include"Macro.h"
#include"GridNav.h"
#include"MapManager.h"


EnemyMovementComponent::EnemyMovementComponent(Actor* _owner) : MovementComponent(_owner)
{
	minRange = 0.5f;
	delaisPath = 1.f;
	astar = new AstarAlgo();
	canMove = true;
	requestTimer = nullptr;
	moveTimer = nullptr;
}

void EnemyMovementComponent::Init()
{
	Component::Init();
}

void EnemyMovementComponent::Request()
{
	index = 0;
	if (!astar || !grid)
		return;
	astar->ComputePath(grid->GetClosesNode(owner->GetShapePosition()), grid->GetClosesNode(MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[0][0]->GetShape()->getPosition()));
}

void EnemyMovementComponent::ChangePoint()
{
	//if (IsAtPosition())
	//	return;
	if (index >= astar->GetPathList().size())
	{
		cout << "CONNARD" << endl;
		Request();
		return;
	}
	destination = Vector2f(astar->GetPathList()[index]->GetShapePosition().x, 0);
	index++;
	cout << "COUCOU" << endl;
}

void EnemyMovementComponent::TimerMove()
{
	SetCallback([&]()
	{
			SetCanMove(false);
			moveTimer = new Timer([&]() {ChangePoint(); }, seconds(0.1f), true, true);
	});
}



