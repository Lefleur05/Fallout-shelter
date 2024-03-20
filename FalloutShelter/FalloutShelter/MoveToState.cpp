#include "MoveToState.h"
#include"FSM.h"
#include"Actor.h"
#include"MoveToTransiton.h"
#include<iostream>

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
	//recuper la destiantion dans le EnemyMovementComponent
}

void MoveToState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
	cout << fsm->GetOwner()->GetID() << " Update MoveTo State" << endl;
}

void MoveToState::Stop()
{
	cout << fsm->GetOwner()->GetID() << "Stop MoveTo State" << endl;
}
