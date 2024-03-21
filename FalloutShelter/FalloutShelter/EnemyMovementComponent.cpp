#include "EnemyMovementComponent.h"
#include"Actor.h"
#include"Macro.h"
#include"GridPointData.h"
#include"MapManager.h"

EnemyMovementComponent::EnemyMovementComponent(Actor* _owner) : MovementComponent(_owner)
{
	minRange = 0.5f;
	destination = Vector2f(0, 0);
	astar = new AstarAlgo();
	data = new GridPointData();
}

void EnemyMovementComponent::Init()
{
	//mettre un timer qui request
}

void EnemyMovementComponent::Update(const float _deltaTime)
{
	MoveTo(_deltaTime);
}

void EnemyMovementComponent::Request(Vector2f _target)
{
	index = 0;
	astar->ComputePath(data->GetClosesNode(owner->GetShapePosition()), data->GetClosesNode(_target));
}

void EnemyMovementComponent::MoveTo(const float _deltaTime)
{
	if (index >= astar->GetPathList().size())
	{
		Request(MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[0][0]->GetShape()->getPosition());
		return;
	}
	destination = Vector2f(astar->GetPathList()[index]->GetShapePosition().x, 0);
	index++;
}




