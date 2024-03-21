#include "State.h"
#include<iostream>

State::State(FSM* _owner)
{
	fsm = _owner;
	nextTransition = nullptr;
}

State::~State()
{
	for (Transition* _transition : transitions)
	{
		delete _transition;
	}
}

void State::Init()
{

}

void State::Start()
{
	
}

void State::Update(const float _deltaTime)
{
	for (Transition* _transition : transitions)
	{
		if (_transition->CanNext())
		{
			nextTransition = _transition;
			return;
		}
	}
	nextTransition = nullptr;
}

void State::Stop()
{

}
