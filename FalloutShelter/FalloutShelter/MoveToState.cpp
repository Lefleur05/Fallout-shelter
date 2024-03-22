#include "MoveToState.h"
#include"FSM.h"
#include"Actor.h"
#include"MoveToTransiton.h"
#include<iostream>
#include "EnemyMovementComponent.h"

MoveToState::MoveToState(FSM* _owner) : State(_owner)
{
	moveToAttack = new MoveToTransiton(_owner);
	moveToAttack->Init();
	transitions.push_back(moveToAttack);

}

void MoveToState::Init()
{
	State::Init();
}

void MoveToState::Start()
{
	State::Start();
}

void MoveToState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
	fsm->GetOwner()->GetComponent<EnemyMovementComponent>()->FollowPath(_deltaTime);
}

void MoveToState::Stop()
{
	cout << fsm->GetOwner()->GetID() << "Stop MoveTo State" << endl;
}
