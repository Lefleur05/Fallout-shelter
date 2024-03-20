#pragma once

class State;
class Transition
{
protected:
	State* nextState = nullptr;

public:
	State* GetNextState()
	{
		return nextState;
	}
public:
	virtual void Init(State* _nextState);
	virtual bool CanNext() const;
};

