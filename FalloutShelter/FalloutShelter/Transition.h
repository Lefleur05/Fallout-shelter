#pragma once

class State;
class FSM;
class Transition
{
protected:
	State* nextState = nullptr;
	FSM* owner = nullptr;
public:
	State* GetNextState()
	{
		return nextState;
	}
public:
	Transition(FSM* _owner);
	virtual void Init(State* _nextState);
	virtual bool CanNext() const;
};

