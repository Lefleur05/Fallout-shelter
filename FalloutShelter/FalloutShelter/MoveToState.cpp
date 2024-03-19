#include "MoveToState.h"
#include"FSM.h"
#include"Actor.h"
#include<iostream>

MoveToState::MoveToState(FSM* _owner) : State(_owner)
{
	//mettre la transition
	//transitions.push_back();
}

void MoveToState::Start()
{
	cout << fsm->GetOwner()->GetID() << "Start MoveTo State" << endl;
}

void MoveToState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
	cout << fsm->GetOwner() << "Update MoveTo State" << endl;
}

void MoveToState::Stop()
{
	cout << fsm->GetOwner() << "Stop MoveTo State" << endl;
}
