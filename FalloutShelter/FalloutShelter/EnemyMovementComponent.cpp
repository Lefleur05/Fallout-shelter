#include "EnemyMovementComponent.h"
#include"Actor.h"
#include"Macro.h"

EnemyMovementComponent::EnemyMovementComponent(Actor* _owner) : MovementComponent(_owner)
{

}

void EnemyMovementComponent::Update(const float _deltaTime)
{

}

void EnemyMovementComponent::MoveTo(const float _deltaTime)
{

}

void EnemyMovementComponent::SetDestination(Vector2f _destination,bool _canMove)
{

}

const bool EnemyMovementComponent::IsAtPosition()
{
	return false;
}

