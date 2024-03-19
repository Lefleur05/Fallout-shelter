#include "FSM.h"


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
	currentState->Update(_deltaTime);
	if(Transition* _transition = currentState->GetNextTransition())
	{
		currentState->Stop();
		currentState = _transition->GetNextState();
		currentState->Start();
	}
}

