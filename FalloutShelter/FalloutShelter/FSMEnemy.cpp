#include "FSMEnemy.h"
#include<iostream>

FSMEnemy::FSMEnemy(Actor* _owner) : FSM(_owner)
{
	moveTo = new MoveToState(this);
	allState.push_back(moveTo);
}

void FSMEnemy::Init()
{
	moveTo->Init();
}
