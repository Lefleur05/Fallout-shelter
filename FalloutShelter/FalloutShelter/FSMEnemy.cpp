#include "FSMEnemy.h"
#include<iostream>

FSMEnemy::FSMEnemy(Actor* _owner) : FSM(_owner)
{
	moveTo = new MoveToState(this);
	allState.push_back(moveTo);

	attack = new AttackState(this);
	allState.push_back(attack);
	
}

void FSMEnemy::Init()
{
	FSM::Init();
	moveTo->Init();
	attack->Init();
	currentState = moveTo;
	currentState->Start();

}
