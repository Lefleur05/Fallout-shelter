#include "MoveToTransiton.h"
#include"FSM.h"
#include"EnemyMovementComponent.h"
#include"Actor.h"

MoveToTransiton::MoveToTransiton(FSM* _owner) : Transition(_owner)
{
}

void MoveToTransiton::Init(State* _nextState)
{
	nextState = _nextState;
}

bool MoveToTransiton::CanNext() const
{
	return owner->GetOwner()->GetComponent<EnemyMovementComponent>()->IsAtPosition();
}
