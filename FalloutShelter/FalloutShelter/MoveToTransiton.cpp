#include "MoveToTransiton.h"
#include"FSM.h"
#include"EnemyMovementComponent.h"
#include"Actor.h"
#include"AttackState.h"
#include "DevUtils.h"

MoveToTransiton::MoveToTransiton(FSM* _owner) : Transition(_owner)
{

}

void MoveToTransiton::Init()
{
	Transition::Init();
	if (!owner)
		return;
	nextState = new AttackState(owner);
}

bool MoveToTransiton::CanNext() const
{
	return owner->GetOwner()->GetComponent<EnemyMovementComponent>()->GetCanAttack();
}

