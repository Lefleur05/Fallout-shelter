#include "AttackState.h"
#include"FSM.h"
#include"Actor.h"
#include"AttackComponent.h"
#include"DevUtils.h"
#include<iostream>

AttackState::AttackState(FSM* _owner) : State(_owner)
{

}

void AttackState::Init()
{
	State::Init();
}

void AttackState::Start()
{
	State::Start();
	fsm->GetOwner()->GetComponent<AttackComponent>()->Attack();
}

void AttackState::Update(const float _deltaTime)
{
	State::Update(_deltaTime);
}

void AttackState::Stop()
{
	State::Stop();
}
