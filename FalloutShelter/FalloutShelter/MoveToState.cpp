#include "MoveToState.h"
#include"FSM.h"
#include"Actor.h"
#include"MoveToTransiton.h"
#include<iostream>
#include "EnemyMovementComponent.h"

MoveToState::MoveToState(FSM* _owner) : State(_owner)
{
	moveToAttack = new MoveToTransiton(_owner);
	transitions.push_back(moveToAttack);
}

void MoveToState::Init()
{
	fsm->SetCurrentState(this);
}

void MoveToState::Start()
{
	cout << fsm->GetOwner()->GetID() << "Start MoveTo State" << endl;
}

void MoveToState::Update(const float _deltaTime)
{
	fsm->GetOwner()->GetComponent<EnemyMovementComponent>()->FollowPath(_deltaTime);
}

void MoveToState::Stop()
{
	cout << fsm->GetOwner()->GetID() << "Stop MoveTo State" << endl;
}
