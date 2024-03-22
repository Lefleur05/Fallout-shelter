#pragma once
#include"State.h"
class AttackState : public State
{

public:
	AttackState(FSM* _owner);
public:
	virtual void Init() override;
	virtual void Start() override;
	virtual void Update(const float _deltaTime) override;
	virtual void Stop() override;
};

