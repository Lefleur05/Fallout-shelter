#include "Transition.h"
#include"State.h"
#include"FSM.h"

Transition::Transition(FSM* _owner)
{
	owner = _owner;
}

void Transition::Init(State* _nextState)
{

}

bool Transition::CanNext() const
{
	return false;
}
