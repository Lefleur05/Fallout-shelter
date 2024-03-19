#include "FSMEnemy.h"


FSMEnemy::FSMEnemy(Actor* _owner) : FSM(_owner)
{
	moveTo = new MoveToState(this);
	allState.push_back(moveTo);
}

void FSMEnemy::Init()
{
	moveTo->Init();
}
