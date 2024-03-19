#include "FSM.h"
#include <iostream>


void FSM::SetCurrentState(State* _currentState)
{
	currentState = _currentState;
}

FSM::FSM(Actor* _owner) : Component(_owner)
{

}

FSM::~FSM()
{
	delete currentState;
}

void FSM::Init()
{

}

void FSM::Update(const float _deltaTime)
{
	if (!currentState)
		return;
	currentState->Update(_deltaTime);
	if(Transition* _transition = currentState->GetNextTransition())
	{
		currentState->Stop();
		currentState = _transition->GetNextState();
		currentState->Start();
	}
}

