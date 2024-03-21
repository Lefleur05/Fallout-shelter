#pragma once
#include"State.h"

class MoveToTransiton;

class MoveToState : public State
{
	MoveToTransiton* moveToAttack;
public:
	MoveToState(FSM* _owner);
public:
	virtual void Init() override;
	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Stop() override;
};

