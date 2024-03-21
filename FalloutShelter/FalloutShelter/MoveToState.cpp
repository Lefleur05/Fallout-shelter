#include "MoveToState.h"
#include"FSM.h"
#include"Actor.h"
#include"MoveToTransiton.h"
#include<iostream>
#include "EnemyMovementComponent.h"

MoveToState::MoveToState(FSM* _owner) : State(_owner)
{
	moveToAttack = new MoveToTransiton();
	transitions.push_back(moveToAttack);
}

void MoveToState::Init()
{
	fsm->SetCurrentState(this);
}

void MoveToState::Start()
{
	cout << fsm->GetOwner()->GetID() << "Start MoveTo State" << endl;
	//fsm->GetOwner()->GetComponent<EnemyMovementComponent>()->TimerMove();
}

void MoveToState::Update(const float _deltaTime)
{
	//cout << fsm->GetOwner()->GetID() << endl;
}

void MoveToState::Stop()
{
	cout << fsm->GetOwner()->GetID() << "Stop MoveTo State" << endl;
}
