#pragma once
#include"State.h"

class MoveToState : public State
{
public:
	MoveToState(FSM* _owner);
public:
	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Stop() override;
};

