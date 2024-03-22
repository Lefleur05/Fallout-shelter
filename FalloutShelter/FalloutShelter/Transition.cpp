#include "Transition.h"
#include"State.h"
#include"FSM.h"

Transition::Transition(FSM* _owner)
{
	owner = _owner;
	nextState = nullptr;
}

void Transition::Init()
{
	
}

bool Transition::CanNext() const
{
	return false;
}
