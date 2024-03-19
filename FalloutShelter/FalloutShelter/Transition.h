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
	virtual void Init();
	virtual bool CanNext() const;
};

